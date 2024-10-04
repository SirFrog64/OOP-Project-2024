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
    return fleet; // Return the fleet vector
}

void Fleet::add_ship(Ship* ship) {
    fleet.push_back(ship); // Using the push_back function, add a ship to the next element in the vector
}

void Fleet::remove_ship(Ship* ship) {
    auto iterator = find(fleet.begin(), fleet.end(), ship); // Create an iterator that iterates from the start to the end.

    if (iterator != fleet.end()) {
        fleet.erase(iterator); // If the iterator finds the ship, erase it from the vector
    }
}
