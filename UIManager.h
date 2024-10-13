#include <SFML/Graphics.hpp>

#include "Button.h"
#include "GameState.h"

#ifndef UIMANAGER_H
#define UIMANAGER_H

class UIManager {
 private:
  sf::Font font;
  GameState& gameState;          // the address of the gameState
  std::vector<Button*> buttons;  // vector of buttons
  sf::RenderWindow* window;      // pointer to game window
  sf::Text playerMoneyText;
  sf::Text windowMessageText;

 public:
  UIManager(GameState& gameState, sf::RenderWindow& window);

  // draw methods
  void drawSideBar(sf::RenderWindow& window);
  void drawButtons(sf::RenderWindow& window);
  void drawCurrentPlayersFleet(sf::RenderWindow& window);

  // THIS FUNCTION WILL NOT BE NEEDED IN THE FINAL VERSION and should be DELETED
  // before handing up vvvvv
  void drawCurrentPlayersFleetCompositionText(sf::RenderWindow& window);

  // common button function getClicked-- TODO: This only exists for specific
  // buttons (abstract), it seems to be working though -- check
  void getClicked(const sf::Vector2f& mousePosition);

  void drawCurrentFleet();

  void drawOpponentFleet();

  void drawCurrentMoney(sf::RenderWindow& window);

  void drawWindowMessage(sf::RenderWindow& window);

  void drawHealthOfBothFleets(sf::RenderWindow& window);

  void drawIndexOfShipsWhileSelecting(sf::RenderWindow& window);

  void drawIndexOfShipsWhileSelectingTarget(sf::RenderWindow& window);
};

#endif