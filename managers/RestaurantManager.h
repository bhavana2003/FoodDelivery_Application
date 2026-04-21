#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include <vector>
#include <algorithm>
#include "../models/Restaurant.h"
using namespace std;

// Singleton class
class RestaurantManager {
    private:
        vector<Restaurant*> restaurants;
        static RestaurantManager* instance;

        RestaurantManager() {

        }
    public:
        static RestaurantManager* getInstance() {
            if (!instance) {
                instance = new RestaurantManager();
            }
            return instance;
        }

        void addRestaurant(Restaurant* restaurant) {
            restaurants.push_back(restaurant);
        }

        vector<Restaurant*> getRestaurants() const {
            return restaurants;
        }

        void deleteRestaurant(Restaurant* restaurant) {
            auto it = find(restaurants.begin(), restaurants.end(), restaurant);
            if (it != restaurants.end()) {
                restaurants.erase(it);
            }
        }

        vector<Restaurant*> searchByLocation(string loc) {
            vector<Restaurant*> result;
            transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
            for (auto r : restaurants) {
                string rl = r->getLocation();
                transform(rl.begin(), rl.end(), rl.begin(), ::tolower);
                if (rl == loc) {
                    result.push_back(r);
                }
            }
            return result;
        }

        ~RestaurantManager() {
            for (auto restaurant : restaurants) {
                delete restaurant;
            }
        }
};

RestaurantManager* RestaurantManager::instance = nullptr;

#endif // RESTAURANTMANAGER_H