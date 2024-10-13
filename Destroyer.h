#ifndef DESTROYER_H
#define DESTROYER_H

#include "Ship.h"

class Destroyer : public Ship {
public:
    Destroyer(int size, int cost, int health, int attack_power, int rank, int hit_prob, sf::RenderWindow* window);
    void attack(Ship* target) override; // each ship has its own attack function(?)
    float get_scale_factor() override; // each ship has its own sprite scale factor
};

#endif

