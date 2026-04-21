#include <iostream>
#include <vector>
#include "Foody.h"
using namespace std;

int main() {
    // Create TomatoApp Object
    Foody* foody = new Foody();

    // Simulate a user coming in (Happy Flow)
    User* user = new User("John Doe", "456 Elm St");
    cout << "User: " << user->getName() << " is active." << endl << endl;

    // User searches restaurants by his location
    vector<Restaurant*> nearbyRestaurants = foody->searchRestaurants(user->getAddress());
    cout << "Restaurants near " << user->getAddress() << ":" << endl;
    for (const auto& restaurant : nearbyRestaurants) {
        cout << "- " << restaurant->getName() << endl;
    }
    cout << endl;

    // User selects a restaurant
    Restaurant* selectedRestaurant = nullptr;
    if (!nearbyRestaurants.empty()) {
        selectedRestaurant = nearbyRestaurants[0];
        cout << "User selected restaurant: " << selectedRestaurant->getName() << endl;
    }
    foody->selectRestaurant(user, selectedRestaurant);

    // User sees the menu of the selected restaurant
    if (selectedRestaurant) {
        vector<MenuItem> menu = selectedRestaurant->getMenu();
        cout << "Menu for " << selectedRestaurant->getName() << ":" << endl;
        for (const auto& item : menu) {
            cout << "- " << item.getItemCode() << "::" << item.getName() << " : $" << item.getCost() << endl;
        }
    }
    cout << endl;

    // User selects a menu item and Adds to cart
    foody->addToCart(user, "M001");
    foody->addToCart(user, "M004");
    foody->addToCart(user, "M005");

    foody->printCart(user);
    cout << endl;
    
    // User Checkout and Pay
    Order* order = foody->checkoutNow(user, "Instant", new UPIPayment("user@upi"));
    if (order) {
        cout << "Order placed successfully!" << endl;
        foody->payForOrder(user, order);
    } else {
        cout << "Failed to place order." << endl;
    }
    cout << endl;
    
    // Cleanup Code.
    delete foody;
    delete user;

    return 0;
}