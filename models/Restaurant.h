#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include <vector>
#include "MenuItem.h"
using namespace std;

class Restaurant {
    private:
    static int nextRestaurantId;
        int restaurantId;
        string name;
        string location;
        vector<MenuItem> menu;
    public:
        Restaurant() {
            this->restaurantId = nextRestaurantId++;
        }

        Restaurant(string name, string location) {
            this->restaurantId = nextRestaurantId++;
            this->name = name;
            this->location = location;
            this->menu = vector<MenuItem>();
        }

        string getName() const {
            return name;
        }

        string getLocation() const {
            return location;
        }

        vector<MenuItem> getMenu() const {
            return menu;
        }

        void setName(string name) {
            this->name = name;
        }

        void setLocation(string location) {
            this->location = location;
        }

        void AddMenuItem(MenuItem menuItem) {
            this->menu.push_back(menuItem);
        }

        ~Restaurant() {
            cout << "Destroying Restaurant: " << name << ", and clearing its menu." << endl;
            menu.clear();
        }
};

int Restaurant::nextRestaurantId = 0;

#endif // RESTAURANT_H