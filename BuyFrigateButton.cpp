#include "BuyFrigateButton.h"

BuyFrigateButton::BuyFrigateButton(int size_x, int size_y, int pos_x, int pos_y,
                                   sf::Color color, const std::string& text,
                                   sf::Font& font, GameState& gameState,
                                   sf::RenderWindow* window)
    : BuyShipButton(size_x, size_y, pos_x, pos_y, color, text, font, gameState,
                    window) {}

void BuyFrigateButton::buttonFunction(sf::RenderWindow& window) {
  std::unique_ptr<Frigate> newFrigate = std::make_unique<Frigate>(
      100, 1500, 600, 150, 2, 80,
      &window);  // this is where we decide the characteristics of the frigate
  bool p1turn = gameState.get_isPlayer1Turn();

  if(p1turn == true) {
    if (newFrigate && gameState.get_player1Money() >= 1500) {  // if a new ship was successfully created
      Fleet& fleet = gameState.getCurrentFleet();
      fleet.add_ship(std::move(newFrigate));
      // cout << "Frigate added to fleet." << std::endl;
      gameState.set_player1Money(gameState.get_player1Money() - 1500);
      gameState.player1MoneyText.setString("P1 - $" + std::to_string(gameState.get_player1Money()));
    }
  }

  if (p1turn == false) {
    if(newFrigate && gameState.get_player2Money() >= 1500) {
      Fleet& fleet = gameState.getCurrentFleet();
      fleet.add_ship(std::move(newFrigate));
      gameState.set_player2Money(gameState.get_player2Money() - 1500);
      gameState.player2MoneyText.setString("P2 - $" + std::to_string(gameState.get_player2Money()));
    }
  } else {
      std::cout << "Failed to create new Frigate."
              << std::endl;  // can be used to debug
  }
}
