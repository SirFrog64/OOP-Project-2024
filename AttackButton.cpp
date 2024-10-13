#include "AttackButton.h"

#include <iostream>

AttackButton::AttackButton(int size_x, int size_y, int pos_x, int pos_y,
                           sf::Color color, std::string text, sf::Font& font,
                           GameState& gameState, sf::RenderWindow* window)
    : Button(size_x, size_y, pos_x, pos_y, color, text, font),
      gameState(gameState),
      window(window) {}

Ship* AttackButton::select_attacking_ship() {
  // cout << gameState.get_iselectingAttackingShip() << endl;
  int position = -1;  // Initialize to an invalid position

  Fleet& currentFleet = gameState.getCurrentFleet();
  vector<Ship*> ships_in_fleet = currentFleet.get_ships();

  // Wait for the player to select a ship
  while (position == -1) {
    // Handle events outside of this loop
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();  // Allow closing the window
      }

      if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
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
            break;  // Ignore other keys
        }

        // If a valid position was selected, break out of the loop
        if (position >= 0 && position < ships_in_fleet.size()) {
          return ships_in_fleet[position];  // Return the selected ship
        }
      }
    }

    // Optionally, you can add a small delay to avoid busy waiting
    sf::sleep(sf::milliseconds(100));  // Prevent busy waiting
  }

  // Return nullptr if no valid selection was made
  gameState.set_currentMessage("Not a valid ship");
  return nullptr;
}

void AttackButton::launch_attack(Ship* attacking_ship) {
  Fleet& opponentFleet =
      gameState.getOpponentFleet();  // Get the opponents fleet
  vector<Ship*> ships_in_opp_fleet =
      opponentFleet
          .get_ships();  // Get the ships in the opponents fleet as a vector

  // Allow the user to select the enemy ship they wish to attack by pressing the
  // number keys Assign the position accordingly
  int position = -1;  // Initialize to an invalid position

  Fleet& currentFleet = gameState.getCurrentFleet();
  vector<Ship*> ships_in_fleet = currentFleet.get_ships();

  // Wait for the player to select a ship
  while (position == -1) {
    // Handle events outside of this loop
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();  // Allow closing the window
      }

      if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
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
            break;  // Ignore other keys
        }
        if (position >= 0 && position < ships_in_opp_fleet.size()) {
          int hit_prob = attacking_ship->get_hit_prob();
          if (attacking_ship->is_hit(
                  hit_prob)) {  // Using the is_hit function, check to see
            // If the hit is successful subtract the attack damage from the
            // targeted ship
            ships_in_opp_fleet[position]->take_damage(
                attacking_ship->get_attack_power());
            std::cout << "Attack Successful" << std::endl;
          } else {
            std::cout << "Attack Unsuccessful" << std::endl;
          }
          return;
        }
      }
    }
  }
}

void AttackButton::buttonFunction(sf::RenderWindow& window) {
  gameState.set_currentMessage("Select ship to attack with:");
  gameState.set_currentState(SelectingAttackingShip);

  // now return

  // Ship* attacking_ship = select_attacking_ship();
  // if (attacking_ship) {
  //   cout << "b utt oN WOWOWO FIRST" << endl;
  // }
  // launch_attack(attacking_ship);
  // cout << "b utt oN WOWOWOW SECOND" << endl;
};