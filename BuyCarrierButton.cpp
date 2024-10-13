#include "BuyCarrierButton.h"

BuyCarrierButton::BuyCarrierButton(int size_x, int size_y, int pos_x, int pos_y,
                                   sf::Color color, const std::string& text,
                                   sf::Font& font, GameState& gameState,
                                   sf::RenderWindow* window)
    : BuyShipButton(size_x, size_y, pos_x, pos_y, color, text, font, gameState,
                    window) {}

void BuyCarrierButton::buttonFunction(sf::RenderWindow& window) {
  std::unique_ptr<Carrier> newCarrier =
      std::make_unique<Carrier>(100, 4000, 1800, 500, 2, 80, &window); // this is where we decide the characteristics of the Carrier

  bool p1turn = gameState.get_isPlayer1Turn();

  if(p1turn == true) {
    if (newCarrier && gameState.get_player1Money() >= 4000) { //if new carrier exists
      Fleet& fleet = gameState.getCurrentFleet();
      fleet.add_ship(std::move(newCarrier));
      gameState.set_player1Money(gameState.get_player1Money() - 4000);
      gameState.player1MoneyText.setString("P1 - $" + std::to_string(gameState.get_player1Money()));
      // std::cout << "Carrier added to fleet." << std::endl;
    }
  }
  
  if(p1turn == false) {
    if(newCarrier && gameState.get_player2Money() >= 4000) {
      Fleet& fleet = gameState.getCurrentFleet();
      fleet.add_ship(std::move(newCarrier)); 
      gameState.set_player2Money(gameState.get_player2Money() - 4000);
      gameState.player2MoneyText.setString("P2 - $" + std::to_string(gameState.get_player2Money())); 
    }
  } else {
    std::cout << "Failed to create new Carrier." << std::endl;  //can be used for debugging
  }
}
