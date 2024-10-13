#include "Ship.h"

Ship::Ship(int size, int cost, int health, int attack_power, int rank,
           int hit_prob, sf::RenderWindow* window)
    : size(size),
      cost(cost),
      health(health),
      attack_power(attack_power),
      rank(rank),
      hit_prob(hit_prob),
      window(window) {
  body.setSize(sf::Vector2f(size, size * 2));
  body.setFillColor(sf::Color(0, 0, 0, 50));  // black, translucent
  isAlive = true;
}

void Ship::take_damage(int damage) {  // this hasnt been made properly, change
                                      // thise for implementation
  health -= damage;
  isAlive = health > 0;
}

int Ship::get_health() const { return health; }
int Ship::get_cost() const { return cost; }
int Ship::get_rank() const { return rank; }
int Ship::get_hit_prob() const { return hit_prob; }
int Ship::get_attack_power() const {
  return attack_power;  // probably not going to be used
}

// im not exactly sure why there is a set_sprite location AND set_texture
// location, but both are used now
void Ship::set_sprite_position(int position_x, int position_y) {
  body.setPosition(position_x, position_y);
  shipSprite.setPosition(position_x + body.getSize().x / 2,
                         position_y + body.getSize().y / 2);
}

void Ship::set_texture(const sf::Texture& texture) {
  shipTexture = texture;
  shipSprite.setTexture(shipTexture);
  shipSprite.setScale(get_scale_factor(), get_scale_factor());
  shipSprite.setOrigin(shipSprite.getLocalBounds().width / 2,
                       shipSprite.getLocalBounds().height / 2);
}

void Ship::draw() {
  if (isAlive) {
    window->draw(body);  // draw the rectangle below the sprite
    window->draw(shipSprite);
  }
}

bool Ship::is_hit(int hit_prob) {
  hit = false;
    int rand_value = rand() % 100 + 1;

    if (rand_value <= hit_prob) {
        hit = true;
    }
    return hit;
}

void Ship::set_sprite_scale(float x, float y) { shipSprite.setScale(x, y); }

float Ship::get_scale_factor() { return 1; } //default is 1

bool Ship::is_alive() { return this->isAlive; }

sf::Vector2f Ship::get_position() { return body.getPosition(); }

Ship::~Ship() {};