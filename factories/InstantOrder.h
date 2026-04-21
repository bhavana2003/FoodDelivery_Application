#ifndef INSTANTORDER_H
#define INSTANTORDER_H

#include <vector>
#include <string>
#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickUpOrder.h"
#include "../utils/Timeutils.h"

class InstantOrder : public OrderFactory {
    public:
        Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuItems,
                           PaymentStrategy* paymentStrategy, const string& orderType) override {
            
            Order* order = nullptr;
            if (orderType == "Delivery") {
                auto deliveryOrder = new DeliveryOrder();
                deliveryOrder->setDeliveryAddress(user->getAddress());
                order = deliveryOrder;
            }
            else {
                auto pickupOrder = new PickUpOrder();
                pickupOrder->setRestaurantAddress(restaurant->getLocation());
                order = pickupOrder;
            }
            order->setUser(user);
            order->setRestaurant(restaurant);
            order->setItems(menuItems);
            order->setPaymentStrategy(paymentStrategy);
            order->setSchedule(TimeUtils::getCurrentTime());
            return order;
        }
};

#endif // INSTANTORDER_H