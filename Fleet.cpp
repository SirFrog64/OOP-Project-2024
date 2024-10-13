#include "Fleet.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

Fleet::Fleet() {
  this->max_num_ships =
      5;             // Max fleet size for either player is 5 (dont change this)
  fleet.reserve(5);  // Set the fleet size to 5 ships
  this->money = 5000;
}

int Fleet::get_num_ships() {
  return fleet.size();  // Return the number of elements(ships) in the vector
}

vector<Ship*> Fleet::get_ships() {  // returns raw pointer of ships
  std::vector<Ship*> ships;
  for (const auto& shipPtr : fleet) {
    ships.push_back(shipPtr.get());
  }
  return ships;
}

void Fleet::add_ship(std::unique_ptr<Ship> ship) {
  if (get_num_ships() < max_num_ships) {
    fleet.push_back(
        std::move(ship));  // Move the unique pointer into the vector
    return;
  }
  // std::cout << "Cannot add ship: Fleet is at maximum capacity." << std::endl;
  // can be used for debugging
  // TODO::: THIS CAN BE DISPLAYED ON SCREEN
}

void Fleet::remove_ship(Ship* ship) {  // THIS HAS NOT BEEN TESTED YET, DELETE
                                       // THIS COMMENT ONCE IMPLEMENTED
  for (size_t i = 0; i < fleet.size(); ++i) {
    if (fleet[i].get() == ship) {
      fleet.erase(fleet.begin() + i);
      break;  // Exit after removing the ship
    }
  }
}

int Fleet::get_money() { return this->money; }
void Fleet::set_money(int amountMoney) { this->money = money + amountMoney; }

int Fleet::get_supplies() { return this->supplies; }
void Fleet::set_supplies(int amountSupplies) {
  this->supplies = supplies + amountSupplies;
}