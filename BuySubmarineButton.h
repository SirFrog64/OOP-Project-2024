#ifndef BUYSUBMARINEBUTTON_H
#define BUYSUBMARINEBUTTON_H

#include <iostream>
#include "BuyShipButton.h"
#include "Submarine.h"

class BuySubmarineButton : public BuyShipButton {
public:
    BuySubmarineButton(int size_x, int size_y, int pos_x, int pos_y,
                       sf::Color color, const std::string& text, sf::Font& font,
                       GameState& gameState, sf::RenderWindow* window);

    void buttonFunction(sf::RenderWindow& window) override; // override to do this buttons functionality
};

#endif
