#include <SFML/Graphics.hpp>
#include <iostream>

#include "Button.h"
#include "Fleet.h"
#include "Ship.h"
#include "UIManager.h"

class AttackButton : public Button {
 protected:
  GameState& gameState;  // Buttons need to be able to access this
  sf::RenderWindow* window;

 public:
  AttackButton(int size_x, int size_y, int pos_x, int pos_y, sf::Color color,
               std::string text, sf::Font& font, GameState& gameState,
               sf::RenderWindow* window);

  Ship* select_attacking_ship();

  void launch_attack(Ship* attacking_ship);

  void buttonFunction(sf::RenderWindow& window)
      override;  // override to do this buttons functionality
};