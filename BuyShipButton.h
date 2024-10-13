#include "Button.h"
#include "Fleet.h"
#include "GameState.h"

#ifndef BUYSHIPBUTTON_H
#define BUYSHIPBUTTON_H

class BuyShipButton : public Button {
 protected:
  // This shouldve been a function to return gamestate in main but its here now
  GameState& gameState;
  sf::RenderWindow* window;

 public:
  BuyShipButton(int size_x, int size_y, int pos_x, int pos_y, sf::Color color,
                const std::string& text, sf::Font& font, GameState& gameState,
                sf::RenderWindow* window);

  // different buy buttons inherit from this, so it is virtual, = 0 works as
  // default
  virtual void buttonFunction(sf::RenderWindow& window) = 0;
};

#endif