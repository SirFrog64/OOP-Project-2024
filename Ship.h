#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>

class Ship {
 protected:
  int health;
  int attack_power;
  int rank;
  int hit_prob;
  int size;
  int cost;
  bool isAlive;
  bool hit;
  sf::RectangleShape body;
  sf::Texture shipTexture;
  sf::Sprite shipSprite;

  sf::RenderWindow* window;

 public:
  Ship(int size, int cost, int health, int attack_power, int rank, int hit_prob,
       sf::RenderWindow* window);
  virtual void attack(Ship* target) = 0;
  void take_damage(int damage);
  // all of these are const so that when they are called they cannot be changed,
  // compiler compains sometimes when not const
  int get_health() const;
  int get_cost() const;
  int get_rank() const;
  int get_hit_prob() const;
  int get_attack_power() const;

  void set_sprite_position(int position_x, int position_y);
  virtual float get_scale_factor();  // Default virtual
  void set_texture(const sf::Texture& texture);
  void draw();
  bool is_hit(int hit_prob);

  virtual ~Ship();

  void set_sprite_scale(float x, float y);

  bool is_alive();

  sf::Vector2f get_position();
};

#endif
