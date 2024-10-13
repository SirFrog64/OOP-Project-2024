#include <SFML/Graphics.hpp>

#include "Fleet.h"

#ifndef GAMESTATE_H
#define GAMESTATE_H

enum GameStateStatus { Default, SelectingAttackingShip, SelectingTargetShip };

class GameState {
 protected:
  bool isPlayer1Turn;
  Fleet player1Fleet;  // fleets are in gamestate so can be accessed in
                       // UIManager, and can be easily accessed by gameState
  Fleet player2Fleet;
  std::string currentMessage;
  GameStateStatus currentState;
  Ship* attackingShip;

  int player1Money = 5000;
  int player2Money = 5000;

  sf::Font font;

 public:

  sf::Text player1MoneyText;
  sf::Text player2MoneyText;

  GameState();

  void set_currentState(GameStateStatus);
  GameStateStatus get_currentState();

  bool get_isPlayer1Turn();

  void next_turn();  // make it the other players turn

  Fleet& getCurrentFleet();  // so other classes can access the fleet
  Fleet& getOpponentFleet();

  std::string get_currentMessage();

  void set_currentMessage(std::string message);

  void handleAttackingShipSelection(sf::Event& e);
  void handleTargetShipSelection(sf::Event& e);

  int get_player1Money();

  int get_player2Money();

  void set_player1Money(int money);

  void set_player2Money(int money);

  void check_for_destroyed();
};

#endif