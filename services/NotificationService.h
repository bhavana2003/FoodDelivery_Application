#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H

#include <iostream>
#include <string>
#include "../models/Order.h"
using namespace std;

class NotificationService {
public:
    static void notify(Order* order) {
        cout << "\nNotification: New " << order->getType() << " order placed!" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Order ID: " << order->getOrderId() << endl;
        cout << "Customer: " << order->getUser()->getName() << endl;
        cout << "Restaurant: " << order->getRestaurant()->getName() << endl;
        cout << "Items Ordered:\n";

        const vector<MenuItem>& items = order->getItems();
        for (auto& item : items) {
            cout << "   - " << item.getName() << " (₹" << item.getCost() << ")\n";
        }

        cout << "Total: ₹" << order->getTotalAmount() << endl;
        cout << "Scheduled For: " << order->getSchedule() << endl;
        cout << "Payment: Done" << endl;
        cout << "---------------------------------------------" << endl;
    }
};

#endif // NOTIFICATION_SERVICE_H