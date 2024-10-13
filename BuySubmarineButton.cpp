#include "BuySubmarineButton.h"

BuySubmarineButton::BuySubmarineButton(int size_x, int size_y, int pos_x,
                                       int pos_y, sf::Color color,
                                       const std::string& text, sf::Font& font,
                                       GameState& gameState,
                                       sf::RenderWindow* window)
    : BuyShipButton(size_x, size_y, pos_x, pos_y, color, text, font, gameState,
                    window) {}

void BuySubmarineButton::buttonFunction(sf::RenderWindow& window) {
  std::unique_ptr<Submarine> newSubmarine =
      std::make_unique<Submarine>(100, 2500, 1000, 400, 2, 80, &window);  // this is where we decide the characteristics of the Submarine
  bool p1turn = gameState.get_isPlayer1Turn();
if (p1turn== true) {
    if (newSubmarine && gameState.get_player1Money() >= 2500) { //if newSubmarine exists
      Fleet& fleet = gameState.getCurrentFleet();
      fleet.add_ship(std::move(newSubmarine));
      // std::cout << "Submarine added to fleet." << std::endl;
      gameState.set_player1Money(gameState.get_player1Money() - 2500);
      gameState.player1MoneyText.setString("P1 - $" + std::to_string(gameState.get_player1Money()));
    }
}
  if (p1turn == false) {
      if(newSubmarine && gameState.get_player2Money() >= 2500) {
        Fleet& fleet = gameState.getCurrentFleet();
        fleet.add_ship(std::move(newSubmarine));
        gameState.set_player2Money(gameState.get_player2Money() - 2500);
        gameState.player2MoneyText.setString("P2 - $" + std::to_string(gameState.get_player2Money()));
      }
    } else {
      std::cout << "Failed to create new Submarine." << std::endl; //can be used for debugging
    }
}
