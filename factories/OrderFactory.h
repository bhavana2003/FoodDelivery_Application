#ifndef ORDERFACTORY_H
#define ORDERFACTORY_H

#include <vector>
#include <string>
#include "../models/Order.h"

using namespace std;

class OrderFactory {
    public:
        virtual Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuItems,
                                    PaymentStrategy* paymentStrategy, const string& orderType) = 0;
        virtual ~OrderFactory() {}
};

#endif // ORDERFACTORY_H