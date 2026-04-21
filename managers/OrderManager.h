#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <iostream>
#include <algorithm>
#include "../models/Order.h"
using namespace std;

// Singleton Class
class OrderManager {
    private:
        vector<Order*> orders;
        static OrderManager* instance;

        OrderManager() {}

    public:
        static OrderManager* getInstance() {
            if (!instance) {
                instance = new OrderManager();
            }
            return instance;
        }

        void addOrder(Order* order) {
            orders.push_back(order);
        }

        void listOrders() {
            cout << "\n--- All Orders ---" << endl;
            for (auto order : orders) {
                cout << order->getType() << " order for " << order->getUser()->getName()
                        << " | Total: ₹" << order->getTotalAmount()
                        << " | At: " << order->getSchedule() << endl;
            }
        }

        void deleteOrder(Order* order) {
            auto it = find(orders.begin(), orders.end(), order);
            if (it != orders.end()) {
                orders.erase(it);
            }
        }

        ~OrderManager() {
            for (auto order : orders) {
                delete order;
            }
        }
};

OrderManager* OrderManager::instance = nullptr;

#endif // ORDERMANAGER_H