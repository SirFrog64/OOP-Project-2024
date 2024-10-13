#include <iostream>

#include "BuyShipButton.h"
#include "Destroyer.h"
#include "Ship.h"

#ifndef BUYDESTROYERBUTTON_H
#define BUYDESTROYERBUTTON_H

class BuyDestroyerButton : public BuyShipButton {
 public:
  BuyDestroyerButton(int size_x, int size_y, int pos_x, int pos_y,
                     sf::Color color, const std::string& text, sf::Font& font,
                     GameState& gameState, sf::RenderWindow* window);

  void buttonFunction(sf::RenderWindow& window) override; // override to do this buttons functionality
};

#endif