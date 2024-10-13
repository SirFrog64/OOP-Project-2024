#ifndef CARRIER_H
#define CARRIER_H

#include "Ship.h"

class Carrier : public Ship {
 public:
  Carrier(int size, int cost, int health, int attack_power, int rank,
          int hit_prob, sf::RenderWindow* window);
  void attack(Ship* target) override; // each ship has its own attack function(?)
  float get_scale_factor() override; // each ship has its own sprite scale factor
};

#endif
