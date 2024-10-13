#include "BuyDestroyerButton.h"

#include "Destroyer.h"

BuyDestroyerButton::BuyDestroyerButton(int size_x, int size_y, int pos_x,
                                       int pos_y, sf::Color color,
                                       const std::string& text, sf::Font& font,
                                       GameState& gameState,
                                       sf::RenderWindow* window)
    : BuyShipButton(size_x, size_y, pos_x, pos_y, color, text, font, gameState,
                    window) {}

void BuyDestroyerButton::buttonFunction(sf::RenderWindow& window) {
  std::unique_ptr<Destroyer> newDestroyer =
      std::make_unique<Destroyer>(100, 5000, 2000, 800, 2, 80, &window); // this is where we decide the characteristics of the Destroyer
  bool p1turn = gameState.get_isPlayer1Turn();
  if(p1turn == true) {
    if(newDestroyer && gameState.get_player1Money() >= 5000) { //if new Destroyer exists
      Fleet& fleet = gameState.getCurrentFleet();
      fleet.add_ship(std::move(newDestroyer));
      gameState.set_player1Money(gameState.get_player1Money() - 5000);
      gameState.player1MoneyText.setString("P1 - $" + std::to_string(gameState.get_player1Money()));
      //std::cout << "Destroyer added to fleet." << std::endl;
    }
  }

  if (p1turn == false) {
    if(newDestroyer && gameState.get_player2Money() >= 5000) {
      Fleet& fleet = gameState.getCurrentFleet();
      fleet.add_ship(std::move(newDestroyer));
      gameState.set_player2Money(gameState.get_player2Money() - 5000);
      gameState.player2MoneyText.setString("P2 - $" + std::to_string(gameState.get_player2Money()));
    }
  } else {
      std::cout << "Failed to create new Destroyer." << std::endl; //can be used for debugging
  }
}