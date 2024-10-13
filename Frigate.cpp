#include "Frigate.h"

#include <iostream>

using namespace sf;

Frigate::Frigate(int size, int cost, int health, int attack_power, int rank,
                 int hit_prob, sf::RenderWindow* window)
    : Ship(size, cost, health, attack_power, rank, hit_prob, window) {
  if (!shipTexture.loadFromFile("Frigate.png")) {
    std::cerr << "Error loading Frigate texture" << std::endl;
  } else {
    set_texture(shipTexture);
  }
}

void Frigate::attack(Ship* target) {
 // ??????????????????
  // if (is_hit()) {
  //   target->take_damage(attack_power);
  //   std::cout << "Attack Successful" << std::endl;
  // } else {
  //   std::cout << "Attack Unsuccessful" << std::endl;
  // }
}

float Frigate::get_scale_factor() { return 0.9; };