#ifndef ENDTURNBUTTON_H
#define ENDTURNBUTTON_H

#include "Button.h"
#include "GameState.h"

class EndTurnButton : public Button {
 private:
  GameState& gameState;  // access to gameState
  bool is_pressed;

 public:
  EndTurnButton(int size_x, int size_y, int pos_x, int pos_y, sf::Color color,
                const std::string& text, sf::Font& font, GameState& gameState);

  void buttonFunction(
      sf::RenderWindow& window) override;  // override from virtual button

  bool get_is_pressed();

  void set_is_pressed(bool value);
};

#endif