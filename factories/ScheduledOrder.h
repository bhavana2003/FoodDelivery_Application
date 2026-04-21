#ifndef SCHEDULEDORDER_H
#define SCHEDULEDORDER_H

#include <vector>
#include <string>
#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickUpOrder.h"

class ScheduledOrder : public OrderFactory {
    private:
        string scheduleTime;
    public:
        ScheduledOrder(const string& scheduleTime){
            this->scheduleTime = scheduleTime;
        }

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
            order->setSchedule(scheduleTime);
            return order;
        }
};


#endif // SCHEDULEDORDER_H