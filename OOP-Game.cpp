#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "BuyCarrierButton.h"
#include "BuyDestroyerButton.h"
#include "BuyFrigateButton.h"
#include "BuyShipButton.h"
#include "BuySubmarineButton.h"
#include "Carrier.h"
#include "Destroyer.h"
#include "EndTurnButton.h"
#include "Fleet.h"
#include "Frigate.h"
#include "GameState.h"
#include "Submarine.h"
#include "UIManager.h"

using namespace sf;

class Boats_N_Battles {
 private:
  sf::RenderWindow* window;
  int size;             // size of window
  std::string title;    // window title
  GameState gameState;  // the game has a gamestate
  UIManager uiManager;  // the game has a uiManager

 public:
  Boats_N_Battles(int size, std::string title)
      : size(size),  // initialise the game
        title(title),
        gameState(),
        window(new sf::RenderWindow(sf::VideoMode(2 * size, size), title)),
        uiManager(gameState,  // make the gameState
                  *window) {  // pass gameState and window to uiManager
  }

  void run_game() {
    while (window->isOpen()) {
      Event e;

      while (window->pollEvent(e)) {
        if (e.type == Event::Closed) {
          window->close();
        }

        if (gameState.get_currentState() == SelectingAttackingShip) {
          // Handle key input for selecting the attacking ship
          gameState.handleAttackingShipSelection(e);
        } else if (gameState.get_currentState() == SelectingTargetShip) {
          // Handle key input for selecting the target ship
          gameState.handleTargetShipSelection(e);
        } else {
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2f mousePosition(static_cast<float>(e.mouseButton.x),
                                       static_cast<float>(e.mouseButton.y));
            uiManager.getClicked(mousePosition);
          }
        }
      }

      gameState.check_for_destroyed();

      ////////~~~~~~~~~~ WINDOW UPDATE~~~~~~~~~~//////////
      window->clear(sf::Color(135, 206, 235));

      // TEST
      uiManager.drawCurrentPlayersFleetCompositionText(
          *window);  // DO NOT KEEP <<<<<

      if (gameState.get_currentState() == SelectingAttackingShip) {
        uiManager.drawIndexOfShipsWhileSelecting(*window);
      } else if (gameState.get_currentState() == SelectingTargetShip) {
        uiManager.drawIndexOfShipsWhileSelectingTarget(*window);
      }

      uiManager.drawSideBar(*window);
      uiManager.drawButtons(*window);
      uiManager.drawCurrentFleet();
      uiManager.drawOpponentFleet();
      uiManager.drawCurrentMoney(*window);
      uiManager.drawWindowMessage(*window);
      window->draw(gameState.player1MoneyText);
      window->draw(gameState.player2MoneyText);
      uiManager.drawHealthOfBothFleets(*window);
      window->display();
      /////////////////////////////////////////////////////
    }
  }

  ~Boats_N_Battles() { delete window; }
};

int main() {
  Boats_N_Battles b1(1000, "Boats 'n Battles");

  b1.run_game();

  return 0;
}