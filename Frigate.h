#ifndef FRIGATE_H
#define FRIGATE_H

#include "Ship.h"

class Frigate : public Ship {
 public:
  Frigate(int size, int cost, int health, int attack_power, int rank,
          int hit_prob, sf::RenderWindow* window);
  void attack(Ship* target) override; // each ship has its own attack function(?)
  float get_scale_factor() override; // each ship has its own sprite scale factor
};

#endif
