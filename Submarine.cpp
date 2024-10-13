#include "Submarine.h"

#include <iostream>

using namespace sf;

Submarine::Submarine(int size, int cost, int health, int attack_power, int rank,
                     int hit_prob, sf::RenderWindow* window)
    : Ship(size, cost, health, attack_power, rank, hit_prob, window) {
  if (!shipTexture.loadFromFile("Submarine.png")) {
    std::cout << "Error loading Submarine texture" << std::endl;
  } else {
    set_texture(shipTexture);
  }
}

void Submarine::attack(Ship* target) {
 // ??????????????????
  // if (is_hit()) {
  //   target->take_damage(attack_power);
  //   std::cout << "Attack Successful" << std::endl;
  // } else {
  //   std::cout << "Attack Unsuccessful" << std::endl;
  // }
}

float Submarine::get_scale_factor() {
  return 0.6;
};  // 0.6 based off size of png