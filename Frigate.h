#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <random>
#include "Ship.h"

#ifndef FRIGATE_H
#define FRIGATE_H

class Frigate : public Ship {
    
    private:
        sf::Texture frigate;
        sf::Sprite frigateSprite;

    public:
        Frigate(int size, int cost, int health, int attack_power, int rank, int hit_prob, sf::RenderWindow* window);

        void render(int position_x, int position_y);

        void set_sprite_position(int position_x, int position_y);

        void draw();

        void attack(Ship* target);

};

#endif