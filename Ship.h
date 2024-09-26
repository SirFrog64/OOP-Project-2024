#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <time.h>

using namespace sf;

#ifndef SHIP_H
#define SHIP_H

class Ship {

    protected:
    // Data types
        int health;
        int attack_power;
        int rank;
        int hit_prob;
        int size;
        int cost;
        bool hit;
        bool isAlive;
        sf::RectangleShape* body;

    // Sprite
        sf::Texture shipTexture;
        sf::Sprite shipSprite;

    // Window
        sf::RenderWindow* window;
        

    public:
        Ship(int size, int health, int attack_power, int rank, int hit_prob, sf::RenderWindow* window) : window(window) {
            body = new sf::RectangleShape(sf::Vector2f(size, 2*size));
            body->setFillColor(sf::Color::Red);
            this-> size = size;
            this-> attack_power = attack_power;
            this-> rank = rank;
            this-> hit_prob = hit_prob;
            this-> health = health;
            this-> isAlive = true;
            srand(time(0));
        }

        virtual void attack(Ship* target) = 0;

        void take_damage(int damage) {
            this-> health = health - damage;
        }

        int get_health() {
            return health;
        }

        int get_cost() {
            return cost;
        }

        int get_rank() {
            return rank;
        }

        int get_hit_prob() {
            return hit_prob;
        }

        int get_attack_power() {
            return attack_power;
        }

        virtual void draw() {
            if (isAlive == true) {
                window->draw(*body);
                window->draw(shipSprite);
            }
        }

        void remove_ship(Ship* target) {
            target->isAlive = false;
        }

        virtual void set_position(int position_x, int position_y) {
            body->setPosition(position_x, position_y);
            shipSprite.setPosition(position_x + body->getSize().x/2, position_y + body->getSize().y/2);
        }

        virtual void render(int x, int y) {}

        bool is_hit(int hit_prob) {
            hit = false;
            int rand_value = rand() % 100 + 1; // Generate a random number between 1 and 100

            if (rand_value <= hit_prob) { // If that value is less than or equal to the hit probability it is a sucessful hit
                hit = true;
            }
            return hit;
        }

        ~Ship() {
            delete body;
        }


};


#endif
