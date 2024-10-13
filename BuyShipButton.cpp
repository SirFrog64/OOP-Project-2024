#include "BuyShipButton.h"

#include "Destroyer.h"
#include "GameState.h"
#include "Ship.h"
#include "Fleet.h"

BuyShipButton::BuyShipButton(int size_x, int size_y, int pos_x, int pos_y,
                             sf::Color color, const std::string& text,
                             sf::Font& font, GameState& gameState,
                             sf::RenderWindow* window)
    : Button(size_x, size_y, pos_x, pos_y, color, text, font),
      gameState(gameState),
      window(window) {};  // iniailise BuyShipButton

void BuyShipButton::buttonFunction(sf::RenderWindow& window) {};
