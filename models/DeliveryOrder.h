#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include <string>
#include "Order.h"
using namespace std;

class DeliveryOrder : public Order {
    private:
        string deliveryAddress;
    public:
        DeliveryOrder() {
            this->deliveryAddress = "";
        }

        string getType() const override {
            return "Delivery";
        }

        void setDeliveryAddress(const string& address) {
            deliveryAddress = address;
        }

        string getDeliveryAddress() const {
            return deliveryAddress;
        }

};

#endif // DELIVERYORDER_H