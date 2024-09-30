#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <random>

using namespace sf;

#ifndef SHIP_H
#define SHIP_H

class Ship {
    protected:
        // Ship Class Data Types
        int health;
        int attack_power;
        int rank;
        int hit_prob;
        int size;
        int cost;
        bool hit;
        bool isAlive;
        sf::RectangleShape* body;

        // Ship Sprite
        sf::Texture shipTexture;
        sf::Sprite shipSprite;

        // Window
        sf::RenderWindow* window;

    public:
        Ship(int size, int cost, int health, int attack_power, int rank, int hit_prob, sf::RenderWindow* window);

        virtual void attack(Ship* target) = 0;

        void take_damage(int damage);

        int get_health();

        int get_cost();

        int get_rank();

        int get_hit_prob();

        int get_attack_power();

        virtual void draw();

        virtual void set_sprite_position(int position_x, int position_y);

        virtual void render(int x, int y) = 0;

        bool is_hit(int hit_prob);

        ~Ship();

};



#endif
