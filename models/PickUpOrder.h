#ifndef PICKUPORDER_H
#define PICKUPORDER_H

#include <string>
#include "Order.h"
using namespace std;

class PickUpOrder : public Order {
    private:
        string restaurantAddress;
    public:
        PickUpOrder() {
            this->restaurantAddress = "";
        }

        void setRestaurantAddress(const string& address) {
            restaurantAddress = address;
        }

        string getRestaurantAddress() const {
            return restaurantAddress;
        }

        string getType() const override {
            return "PickUp";
        }
};

#endif // PICKUPORDER_H