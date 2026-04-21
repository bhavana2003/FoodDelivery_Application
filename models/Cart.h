#ifndef CART_H
#define CART_H

#include <iostream>
#include <string>
#include "MenuItem.h"
#include "Restaurant.h"
using namespace std;

class Cart {
    private:
        double total;
        Restaurant* restaurant;
        vector<MenuItem> items;
    public:
        Cart() {
            this->total = 0;
            this->items = vector<MenuItem>();
            this->restaurant = nullptr;
        }

        void addToCart(MenuItem item) {
            if (!restaurant) {
                cerr << "Cart: Set a restaurant before adding items." << endl;
                return;
            }
            this->items.push_back(item);
            this->total += item.getCost();
        }

        void removeFromCart(MenuItem item) {
            for (auto it = items.begin(); it != items.end(); ++it) {
                if (it->getItemCode() == item.getItemCode()) {
                    total -= it->getCost();
                    items.erase(it);
                    break;
                }
            }
        }

        double getTotal() const {
            return total;
        }

        bool isEmpty() const {
            return (!restaurant || items.empty());
        }

        void clear() {
            items.clear();
            restaurant = nullptr;
        }

        vector<MenuItem> getItems() const {
            return items;
        }

        void setRestaurant(Restaurant* restaurant) {
            this->restaurant = restaurant;
        }

        Restaurant* getRestaurant() const {
            return restaurant;
        }

        ~Cart() {
            cout << "Destroying Cart with total: " << total << " and clearing its items." << endl;
            items.clear();
        }
};

#endif // CART_H