#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Ship.h"

using namespace std;

#ifndef FLEET_H
#define FLEET_H

class Fleet {
 private:
  int max_num_ships;  // this is decided in constructor, but its pretty built in
                      // to be 5 already
  vector<std::unique_ptr<Ship>> fleet;  // vector of ships in fleet

  int money;

  int supplies;

 public:
  Fleet();

  int get_num_ships();

  vector<Ship*>
  get_ships();  // returns the vector of ships in the fleet (raw pointers)

  void add_ship(std::unique_ptr<Ship> ship);

  void remove_ship(Ship* ship);

  int get_money();
  void set_money(int amountMoney);

  int get_supplies();
  void set_supplies(int amountSupplies);
};

#endif