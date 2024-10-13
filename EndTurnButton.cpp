#include "EndTurnButton.h"

EndTurnButton::EndTurnButton(int size_x, int size_y, int pos_x, int pos_y,
                             sf::Color color, const std::string& text,
                             sf::Font& font, GameState& gameState)
    : Button(size_x, size_y, pos_x, pos_y, color, text, font),
      gameState(gameState) {}

void EndTurnButton::buttonFunction(sf::RenderWindow& window) {
  gameState.next_turn();  // make it next players turn
  is_pressed = true;
}

bool EndTurnButton::get_is_pressed() {
  return is_pressed;
}

void EndTurnButton::set_is_pressed(bool value) {
    this-> is_pressed = value;
}