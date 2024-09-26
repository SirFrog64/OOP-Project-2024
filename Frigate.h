#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ship.h"

#ifndef FRIGATE_H
#define FRIGATE_H

class Frigate : public Ship {

    private:
    sf::Texture frigate;
    sf::Sprite frigateSprite;

    public:
        Frigate(int size, int health, int attack_power, int rank, int hit_prob, sf::RenderWindow* window) : Ship(size, health, attack_power, rank, hit_prob, window){
            this-> size = size;
            this-> attack_power = attack_power;
            this-> rank = rank;
            this-> hit_prob = hit_prob;
            this-> health = health;
            srand(time(0));
        }

        void render(int position_x, int position_y) {
            frigate.loadFromFile("frigate.png");
            frigateSprite.setTexture(frigate);
            frigateSprite.setPosition(sf::Vector2f(position_x, position_y));
            frigateSprite.setOrigin(frigate.getSize().x/2, frigate.getSize().y/2);

        }

        void set_position(int position_x, int position_y) {
            body->setPosition(position_x, position_y);
            frigateSprite.setPosition(position_x + body->getSize().x/2, position_y + body->getSize().y/2);
        }

        void draw() {
            window->draw(*body);
            window->draw(frigateSprite);
        }

        void attack(Ship* target) {
                if(is_hit(hit_prob) == true) {
                    target->take_damage(attack_power);
                    std::cout << "Attack Successful" << std::endl;
                }
                std::cout << "Attack Unsuccessful" << std::endl;
        }
};


#endif