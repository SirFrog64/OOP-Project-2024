#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <random>
#include "Ship.h"
#include "Frigate.h"

Frigate::Frigate(int size, int cost, int health, int attack_power, int rank, int hit_prob, sf::RenderWindow* window) : Ship(size, cost, health, attack_power, rank, hit_prob, window) {
    this-> size = size;
    this-> cost = cost;
    this-> attack_power = attack_power;
    this-> rank = rank;
    this-> hit_prob = hit_prob;
    this-> health = health;
    srand(time(0));
}

void Frigate::render(int position_x, int position_y) { 
    frigate.loadFromFile("Frigate.png");
    frigateSprite.setTexture(frigate);
    frigateSprite.setPosition(sf::Vector2f(position_x, position_y));
    frigateSprite.setOrigin(frigate.getSize().x/2, frigate.getSize().y/2);
}

void Frigate::set_sprite_position(int position_x, int position_y) {
    body->setPosition(position_x, position_y);
    frigateSprite.setPosition(position_x + body->getSize().x/2, position_y + body->getSize().y/2);
}

void Frigate::draw() {
    window->draw(*body);
    window->draw(frigateSprite);
}

void Frigate::attack(Ship* target) {
    if(is_hit(hit_prob) == true) {
        target->take_damage(attack_power);
        std::cout << "Attack Successful" << std::endl;
    }
    std::cout << "Attack Unsuccessful" << std::endl;
}

