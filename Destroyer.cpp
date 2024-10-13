#include "Destroyer.h"

#include <iostream>

Destroyer::Destroyer(int size, int cost, int health, int attack_power, int rank,
                     int hit_prob, sf::RenderWindow* window)
    : Ship(size, cost, health, attack_power, rank, hit_prob, window) {
  if (!shipTexture.loadFromFile("Destroyer.png")) {
    std::cerr << "Error loading Destroyer texture" << std::endl;
  } else {
    set_texture(shipTexture);
  }
}

void Destroyer::attack(Ship* target) {
  // ??????????????????
  // if (is_hit()) {
  //   target->take_damage(attack_power);
  //   std::cout << "Attack Successful" << std::endl;
  // } else {
  //   std::cout << "Attack Unsuccessful" << std::endl;
  // }
}

float Destroyer::get_scale_factor() {
  return 0.3;
};  // 0.3 based off size of png