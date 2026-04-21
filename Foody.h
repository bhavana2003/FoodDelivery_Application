#ifndef FOODY_H
#define FOODY_H

#include <iostream>
#include <string>
#include <vector>
#include "models/User.h"
#include "models/Restaurant.h"
#include "models/MenuItem.h"
#include "models/Cart.h"
#include "models/Order.h"
#include "factories/OrderFactory.h"
#include "factories/InstantOrder.h"
#include "factories/ScheduledOrder.h"
#include "managers/RestaurantManager.h"
#include "managers/OrderManager.h"
#include "strategies/payment/PaymentStrategy.h"
#include "strategies/payment/CardPayment.h"
#include "strategies/payment/UPIPayment.h"
#include "services/NotificationService.h"
#include "utils/TimeUtils.h"
using namespace std;

class Foody {
    public:
        Foody() {
            InitialiseRestaurants();
        }

        void InitialiseRestaurants() {
            Restaurant* R1 = new Restaurant("Pizza Place", "123 Main St");
            R1->AddMenuItem(MenuItem("M001", "Margherita Pizza", 10.99));
            R1->AddMenuItem(MenuItem("M002", "Pepperoni Pizza", 12.99));
            R1->AddMenuItem(MenuItem("M003", "Veggie Pizza", 11.99));

            Restaurant* R2 = new Restaurant("Burger Joint", "456 Elm St");
            R2->AddMenuItem(MenuItem("M004", "Cheeseburger", 8.99));
            R2->AddMenuItem(MenuItem("M005", "Bacon Burger", 9.99));
            R2->AddMenuItem(MenuItem("M006", "Veggie Burger", 7.99));

            Restaurant* R3 = new Restaurant("Sushi Spot", "789 Oak St");
            R3->AddMenuItem(MenuItem("M007", "California Roll", 6.99));
            R3->AddMenuItem(MenuItem("M008", "Spicy Tuna Roll", 7.99));
            R3->AddMenuItem(MenuItem("M009", "Vegetable Roll", 5.99));

            RestaurantManager* restaurantManager = RestaurantManager::getInstance();
            restaurantManager->addRestaurant(R1);
            restaurantManager->addRestaurant(R2);
            restaurantManager->addRestaurant(R3);
        }

        vector<Restaurant*> searchRestaurants(const string& location) {
            return RestaurantManager::getInstance()->searchByLocation(location);
        }

        void selectRestaurant(User* user, Restaurant* restaurant) {
            Cart* cart = user->getCart();
            cart->setRestaurant(restaurant);
        }

        // Checking if Item present in restaurant menu before adding to cart
        void addToCart(User* user, const string& itemCode) {
            Restaurant* restaurant = user->getCart()->getRestaurant();
            if (!restaurant) {
                cout << "Please select a restaurant first." << endl;
                return;
            }
            for (const auto& item : restaurant->getMenu()) {
                if (item.getItemCode() == itemCode) {
                    user->getCart()->addToCart(item);
                    break;
                }
            }
        }

        Order* checkoutNow(User* user, const string& orderType, PaymentStrategy* paymentStrategy) {
            return checkout(user, orderType, paymentStrategy, new InstantOrder());
        }

        Order* checkoutScheduled(User* user, const string& orderType, PaymentStrategy* paymentStrategy, const string& scheduleTime) {
            return checkout(user, orderType, paymentStrategy, new ScheduledOrder(scheduleTime));
        }

        Order* checkout(User* user, const string& orderType, PaymentStrategy* paymentStrategy, OrderFactory* orderFactory) {
            if (user->getCart()->isEmpty())
                return nullptr;

            Cart* userCart = user->getCart();
            Restaurant* orderedRestaurant = userCart->getRestaurant();
            vector<MenuItem> itemsOrdered = userCart->getItems();
            double totalCost = userCart->getTotal();

            Order* order = orderFactory->createOrder(user, userCart, orderedRestaurant, itemsOrdered, paymentStrategy, orderType);
            OrderManager::getInstance()->addOrder(order);
            return order;
        }

        void payForOrder(User* user, Order* order) {
            bool isPaymentSuccess = order->processPayment();

            // clear user cart if payment is successful.
            if(isPaymentSuccess) {
                NotificationService* notification = new NotificationService();
                notification->notify(order);
                user->getCart()->clear();
            }  
        }

        void printCart(User* user) {
            cout << "Items in cart:" << endl;
            cout << "------------------------------------" << endl;
            for (const auto& item : user->getCart()->getItems()) {
                cout << item.getItemCode() << " : " << item.getName() << " : ₹" << item.getCost() << endl;
            }
            cout << "------------------------------------" << endl;
            cout << "Grand total : ₹" << user->getCart()->getTotal() << endl;
        }

};

#endif // FOODY_H