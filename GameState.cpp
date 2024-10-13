#include "GameState.h"

GameState::GameState() {
  this->isPlayer1Turn = true;  // when the game starts it is player 1s turn
  this->currentState = Default;
  this->attackingShip = nullptr;

  player1MoneyText.setFont(font);
  player1MoneyText.setString("P1 - $" + std::to_string(get_player1Money()));
  player1MoneyText.setCharacterSize(25);
  player1MoneyText.setFillColor(sf::Color::Black);
  player1MoneyText.setPosition(10,10);

  player2MoneyText.setFont(font);
  player2MoneyText.setString("P2 - $" + std::to_string(get_player2Money()));
  player2MoneyText.setCharacterSize(25);
  player2MoneyText.setFillColor(sf::Color::Black);
  player2MoneyText.setPosition(10,950);  // pass gameState and window to uiManager
    
  if (!font.loadFromFile("/home/tyson/cpp_PROJECT/Folder6/ARIAL.TTF")) {
    std::cout << "Font error" << std::endl;
  }
}

void GameState::set_currentState(GameStateStatus state) {
  currentState = state;
}

GameStateStatus GameState::get_currentState() { return currentState; }

bool GameState::get_isPlayer1Turn() { return isPlayer1Turn; }

void GameState::next_turn() {
  if (isPlayer1Turn == true) {
    set_player1Money(player1Money + 2000);
    player1MoneyText.setString("P1 - $" + std::to_string(get_player1Money()));
    isPlayer1Turn = false;  // if player1turn, make player2turn
  } else {
    set_player2Money(player2Money + 2000);
    player2MoneyText.setString("P2 - $" + std::to_string(player2Money));
    isPlayer1Turn = true;  // if player2turn, make player1turn
  }
}

Fleet& GameState::getCurrentFleet() {
  if (isPlayer1Turn == true) {
    return player1Fleet;  // currently player 1
  } else {
    return player2Fleet;
  }
}

Fleet& GameState::getOpponentFleet() {
  if (isPlayer1Turn == true) {
    return player2Fleet;  // currently player 1
  } else {
    return player1Fleet;
  }
}

std::string GameState::get_currentMessage() { return this->currentMessage; }

void GameState::set_currentMessage(std::string message) {
  this->currentMessage = message;
}

void GameState::handleAttackingShipSelection(sf::Event& e) {
  Fleet& currentFleet = getCurrentFleet();
  std::vector<Ship*> ships_in_fleet = currentFleet.get_ships();

  if (e.type == sf::Event::KeyPressed) {
    int position = -1;

    switch (e.key.code) {
      case sf::Keyboard::Num1:
        position = 0;
        break;
      case sf::Keyboard::Num2:
        position = 1;
        break;
      case sf::Keyboard::Num3:
        position = 2;
        break;
      case sf::Keyboard::Num4:
        position = 3;
        break;
      case sf::Keyboard::Num5:
        position = 4;
        break;
      default:
        break;
    }

    if (position >= 0 && position < ships_in_fleet.size()) {
      // Valid ship selected
      set_currentMessage("Choose enemy ship to attack:");
      currentState = SelectingTargetShip;  // Change state
      this->attackingShip = ships_in_fleet[position];
    } else {
      set_currentMessage("Not a valid ship");
    }
  }
}

void GameState::handleTargetShipSelection(sf::Event& e) {
  Fleet& opponentFleet = getOpponentFleet();
  std::vector<Ship*> ships_in_opp_fleet = opponentFleet.get_ships();

  if (e.type == sf::Event::KeyPressed) {
    int position = -1;

    switch (e.key.code) {
      case sf::Keyboard::Num1:
        position = 0;
        break;
      case sf::Keyboard::Num2:
        position = 1;
        break;
      case sf::Keyboard::Num3:
        position = 2;
        break;
      case sf::Keyboard::Num4:
        position = 3;
        break;
      case sf::Keyboard::Num5:
        position = 4;
        break;
      default:
        break;
    }

    if (position >= 0 && position < ships_in_opp_fleet.size()) {
      int hit_prob = attackingShip->get_hit_prob();
      if (attackingShip->is_hit(
              hit_prob)) {  // Using the is_hit function, check to see
        // If the hit is successful subtract the attack damage from the
        // targeted ship
        ships_in_opp_fleet[position]->take_damage(
            attackingShip->get_attack_power());
        std::cout << "Attack Successful" << std::endl;
      } else {
        std::cout << "Attack Unsuccessful" << std::endl;
      }
      set_currentMessage("");
      currentState = Default;
      return;
    }
  }
}

int GameState::get_player1Money() {
  return player1Money;
}

int GameState::get_player2Money() {
  return player2Money;
}

void GameState::set_player1Money(int money) {
  this->player1Money = money;
}

void GameState::set_player2Money(int money) {
  this->player2Money = money;
}

void GameState::check_for_destroyed() {
  // Get the ships in the player 1 fleet
  vector<Ship*> ships_in_fleet1 = player1Fleet.get_ships();

  // Get the ships in the player 2 fleet
  vector<Ship*> ships_in_fleet2 = player2Fleet.get_ships();

  for(const auto& shipPtr : ships_in_fleet1) { // Loop through P1 fleet to find any destroyed ships
      if(shipPtr->get_health() <= 0) {
        player1Fleet.remove_ship(shipPtr);
      } 
  }

  for (const auto& shipPtr : ships_in_fleet2) {
    if(shipPtr->get_health() <= 0) {
      player2Fleet.remove_ship(shipPtr);
    }
  }
}