#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <random>
#include "Ship.h"

using namespace sf;

Ship::Ship(int size, int cost, int health, int attack_power, int rank, int hit_prob, sf::RenderWindow* window) : window(window) {
            body = new sf::RectangleShape(sf::Vector2f(size, size*2));
            body->setFillColor(sf::Color(135, 206, 235));
            this-> size = size;
            this-> cost = cost;
            this-> attack_power = attack_power;
            this-> rank = rank;
            this-> hit_prob = hit_prob;
            this-> health = health;
            srand(time(0));
}

void Ship::take_damage(int damage) {
    this-> health = health - damage;

}

int Ship::get_health() {
    return health;
}

int Ship::get_cost() {
    return cost;
}

int Ship::get_rank() {
    return rank;
}

int Ship::get_hit_prob() {
    return hit_prob;
}

int Ship::get_attack_power() {
    return attack_power;
}

void Ship::draw() {
    window->draw(*body);
    window->draw(shipSprite);
}

void Ship::set_sprite_position(int position_x, int position_y) {
    body->setPosition(position_x, position_y);
    shipSprite.setPosition(position_x + body->getSize().x/2, position_y + body->getSize().y/2);
}

bool Ship::is_hit(int hit_prob) {
    hit = false;
    int rand_value = rand() % 100 + 1;

    if (rand_value <= hit_prob) {
        hit = true;
    }
    return hit;
}

Ship::~Ship() {
    delete body;
}