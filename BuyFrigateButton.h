#ifndef BUYFRIGATEBUTTON_H
#define BUYFRIGATEBUTTON_H

#include <iostream>

#include "BuyShipButton.h"
#include "Frigate.h"

class BuyFrigateButton : public BuyShipButton {
 public:
  BuyFrigateButton(int size_x, int size_y, int pos_x, int pos_y,
                   sf::Color color, const std::string& text, sf::Font& font,
                   GameState& gameState, sf::RenderWindow* window);

  void buttonFunction(sf::RenderWindow& window)
      override;  // override to do this buttons functionality
};

#endif
