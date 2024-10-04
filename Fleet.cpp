#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Fleet.h"

using namespace std;

Fleet::Fleet() {
    this-> max_num_ships = 5; // Max fleet size for either player is 5
    fleet.reserve(5); // Set the fleet size to 5 ships
}

int Fleet::get_num_ships() {
    return fleet.size(); // Return the number of elements in the vector
}

vector<Ship*> Fleet::get_ships() {
    return fleet;
}

void Fleet::add_ship(Ship* ship) {
    fleet.push_back(ship);
}

void Fleet::remove_ship(Ship* ship) {
    auto iterator = find(fleet.begin(), fleet.end(), ship);

    if (iterator != fleet.end()) {
        fleet.erase(iterator);
    }
}