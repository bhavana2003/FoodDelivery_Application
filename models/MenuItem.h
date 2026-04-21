#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>
using namespace std;

class MenuItem {
    private:
        string itemCode;
        string name;
        double cost;

    public:
        MenuItem() {

        }

        MenuItem(string itemCode, string name, double cost) {
            this->itemCode = itemCode;
            this->name = name;
            this->cost = cost;
        }

        string getItemCode() const {
            return itemCode;
        }

        string getName() const {
            return name;
        }

        double getCost() const {
            return cost;
        }

        void setItemCode(string itemCode) {
            this->itemCode = itemCode;
        }

        void setName(string name) {
            this->name = name;
        }

        void setCost(double cost) {
            this->cost = cost;
        }
};

#endif // MENUITEM_H