#ifndef BUYCARRIERBUTTON_H
#define BUYCARRIERBUTTON_H

#include <iostream>

#include "BuyShipButton.h"
#include "Carrier.h"

class BuyCarrierButton : public BuyShipButton {
 public:
  BuyCarrierButton(int size_x, int size_y, int pos_x, int pos_y,
                   sf::Color color, const std::string& text, sf::Font& font,
                   GameState& gameState, sf::RenderWindow* window);

  void buttonFunction(sf::RenderWindow& window) override; // override to do this buttons functionality
};

#endif
