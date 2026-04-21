#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Restaurant.h"
#include "MenuItem.h"
#include "../strategies/payment/PaymentStrategy.h"
using namespace std;

class Order {
    private:
        static int nextOrderId;
        int orderId;
        double totalAmount;
        User* user;
        Restaurant* restaurant;
        vector<MenuItem> items;
        string schedule;
        PaymentStrategy* paymentStrategy;  

    public:
        Order() {
            this->orderId = nextOrderId++;
            this->totalAmount = 0;
            this->user = nullptr;
            this->restaurant = nullptr;
            this->paymentStrategy = nullptr;
            this->items = vector<MenuItem>();
            this->schedule = "";
        }

        virtual string getType() const = 0;

        int getOrderId() const {
            return orderId;
        }

        void setUser(User* user) {
            this->user = user;
        }

        User* getUser() const {
            return user;
        }

        void setRestaurant(Restaurant* restaurant) {
            this->restaurant = restaurant;
        }

        Restaurant* getRestaurant() const {
            return restaurant;
        }

        vector<MenuItem> getItems() const {
            return items;
        }

        void setItems(const vector<MenuItem>& items) {
            this->items = items;
            totalAmount = 0;
            for (auto& item : this->items) {
                totalAmount += item.getCost();
            }
        }

        double getTotalAmount() const {
            return totalAmount;
        }

        void setSchedule(const string& schedule) {
            this->schedule = schedule;
        }

        string getSchedule() const {
            return schedule;
        }

        void setPaymentStrategy(PaymentStrategy* p) {
            paymentStrategy = p;
        }

        bool processPayment(){
            if (paymentStrategy) {
                paymentStrategy->pay(this->totalAmount);
                return true;
            }
            else {
                cout << "Please choose a payment mode first" << endl;
                return false;
            }
        }

        virtual ~Order() {
            if (paymentStrategy) {
                delete paymentStrategy;
            }
        }
};

int Order::nextOrderId = 0;

#endif // ORDER_H