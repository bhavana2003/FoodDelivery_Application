#ifndef USER_H
#define USER_H

#include <iostream>
#include "Cart.h"
using namespace std;

class User {
    private:
        static int nextUserId;
        int userId;
        string name;
        string address;
        Cart* cart;
    
    public:
        User(string name, string address) {
            this->userId = nextUserId++;
            this->name = name;
            this->address = address;
            this->cart = new Cart();
        }

        int getUserId() const {
            return userId;
        }

        string getName() const {
            return name;
        }

        string getAddress() const {
            return address;
        }

        void setName(string name) {
            this->name = name;
        }

        void setAddress(string address) {
            this->address = address;
        }

        Cart* getCart() const {
            return cart;
        }

        ~User() {
            cout << "Destroying User: " << name << ", and deleting their cart." << endl;
            delete cart;
        }
};

int User::nextUserId = 0;

#endif // USER_H