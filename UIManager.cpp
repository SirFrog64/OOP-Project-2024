#include "UIManager.h"

#include <iostream>
#include <sstream>
#include <vector>

#include "Fleet.h"

// must include all classes of buttons //
#include "AttackButton.h"
#include "BuyCarrierButton.h"
#include "BuyDestroyerButton.h"
#include "BuyFrigateButton.h"
#include "BuyShipButton.h"
#include "BuySubmarineButton.h"
#include "EndTurnButton.h"
/////////////////////////////////////////

#include "Fleet.h"

UIManager::UIManager(GameState& gameState, sf::RenderWindow& window)
    : gameState(gameState),
      window(&window) {  // initialise with passed down gameState and window
  if (!font.loadFromFile("ARIAL.TTF")) {
    std::cout << "Font error" << std::endl;
  }
  // initialise all PERMAMANENt buttons in UIManager constructor here:
  buttons.push_back(  // when a button is initialised it is added to the buttons
                      // vector, this is necessary so when there is a left click
                      // in main it can check all buttons
      new BuyDestroyerButton(150, 60, 1050, 250, sf::Color(22, 129, 24),
                             "Buy Destroyer", font, gameState, &window));
  buttons.push_back(new BuyCarrierButton(150, 60, 1050, 350,
                                         sf::Color(22, 129, 24), "Buy Carrier",
                                         font, gameState, &window));
  buttons.push_back(
      new BuySubmarineButton(150, 60, 1250, 250, sf::Color(22, 129, 24),
                             "Buy Submarine", font, gameState, &window));
  buttons.push_back(new BuyFrigateButton(150, 60, 1250, 350,
                                         sf::Color(22, 129, 24), "Buy Frigate",
                                         font, gameState, &window));
  buttons.push_back(new EndTurnButton(
      300, 60, 1090, 720, sf::Color(165, 42, 42), "END TURN", font, gameState));
  buttons.push_back(new AttackButton(300, 60, 1090, 600, sf::Color::Red,
                                     "Attack", font, gameState, &window));
}

void UIManager::drawSideBar(sf::RenderWindow& window) {
  // sidebar
  sf::RectangleShape sidebar;
  sidebar.setSize(sf::Vector2f(450, 780));
  sidebar.setPosition(1010, 10);

  if (gameState.get_isPlayer1Turn()) {              // player 1 side bar
    sidebar.setFillColor(sf::Color(59, 170, 200));  // light blue
    sidebar.setOutlineThickness(10);
    sidebar.setOutlineColor(sf::Color(30, 58, 76));  // dark blue
  } else {                                           // player 2 side bar
    sidebar.setFillColor(sf::Color(212, 63, 63));    // light red
    sidebar.setOutlineThickness(10);
    sidebar.setOutlineColor(sf::Color(99, 11, 11));  // dark red
  }
  window.draw(sidebar);

  // player text in sidebar
  sf::Text playerTitle;
  playerTitle.setFont(font);
  playerTitle.setString(
      gameState.get_isPlayer1Turn()
          ? "PLAYER ONE"  // if is player 1, otherwise player 2
          : "PLAYER TWO");
  playerTitle.setCharacterSize(40);
  playerTitle.setFillColor(sf::Color::White);
  playerTitle.setPosition(1120, 20);
  window.draw(playerTitle);
}

void UIManager::drawButtons(sf::RenderWindow& window) {
  for (auto& button : buttons) {  // loop through array of buttons
    button->draw(window);         // draw each button
  }
}

void UIManager::getClicked(const sf::Vector2f& mousePosition) {
  for (auto& button : buttons) {  // auto so the buttons cant be changed
    if (button->isClickInButtonBounds(mousePosition)) {
      button->buttonFunction(*window);  // pass window to button clicked
    }
  }
}

// THIS FUNCTION WILL NOT BE NEEDED IN THE FINAL VERSION and should be DELETED
void UIManager::drawCurrentPlayersFleetCompositionText(
    sf::RenderWindow& window) {
  // Retrieve the fleet from the game state
  Fleet& fleet = gameState.getCurrentFleet();
  std::vector<Ship*> ships = fleet.get_ships();

  // Set up the text properties
  sf::Text fleetText;
  fleetText.setFont(font);
  fleetText.setCharacterSize(24);  // Set character size for the text
  fleetText.setFillColor(sf::Color::White);
  fleetText.setPosition(20, 100);  // Position where you want to start drawing

  // Create a string to hold the fleet composition text
  std::string displayText;
  for (const auto& ship : ships) {
    displayText += (ship == nullptr
                        ? "0\n"
                        : "1\n");  // Represent nullptr with 0, Destroyer with 1
  }

  fleetText.setString(displayText);  // Set the text to the text object
  window.draw(fleetText);            // Draw the text to the window
}

void UIManager::drawCurrentFleet() {
  Fleet& currentFleet =
      gameState.getCurrentFleet();  // get address of current fleet
  auto ships_in_fleet =
      currentFleet.get_ships();  // copy current ships over using auto so they
                                 // cant be changed accidentally
  for (int i = 0; i < ships_in_fleet.size(); i++) {
    Ship* ship = ships_in_fleet[i];  // current ship in loop
    if (ship) {                      // if ship exists
      // draw the ship
      float scale = ship->get_scale_factor();
      ship->set_sprite_scale(scale, scale);
      ship->set_sprite_position(50 + i * 175, 550);
      ship->draw();
    }
  }
}

void UIManager::drawOpponentFleet() {  // draw opponent fleet at top of screen
  Fleet& opponentFleet = gameState.getOpponentFleet();  //""
  auto ships_in_opp_fleet = opponentFleet.get_ships();  //""

  for (int i = 0; i < ships_in_opp_fleet.size(); i++) {
    Ship* ship = ships_in_opp_fleet[i];
    if (ship) {
      float scale = ship->get_scale_factor();
      ship->set_sprite_scale(-scale, -scale);  // negatives flip the ships
                                               // around
      ship->set_sprite_position(50 + i * 175, 50);
      ship->draw();
    }
  }
}

void UIManager::drawCurrentMoney(sf::RenderWindow& window) {
  Fleet& currentFleet = gameState.getCurrentFleet();

  playerMoneyText.setFont(font);
  playerMoneyText.setString("Money: $" +
                            std::to_string(currentFleet.get_money()));
  playerMoneyText.setCharacterSize(25);
  playerMoneyText.setFillColor(sf::Color::Black);
  playerMoneyText.setPosition(1055, 100);
  window.draw(playerMoneyText);
};

void UIManager::drawWindowMessage(sf::RenderWindow& window) {
  windowMessageText.setFont(font);
  windowMessageText.setString(gameState.get_currentMessage());
  windowMessageText.setCharacterSize(25);
  windowMessageText.setFillColor(sf::Color::Red);
  windowMessageText.setPosition(350, 400);
  window.draw(windowMessageText);
}

void UIManager::drawHealthOfBothFleets(sf::RenderWindow& window) {
  Fleet& currentFleet =
      gameState.getCurrentFleet();  // get address of current fleet
  auto ships_in_fleet = currentFleet.get_ships();

  for (const auto& ship : ships_in_fleet) {
    if (ship->is_alive()) {
      sf::Text healthText;
      healthText.setFont(font);
      healthText.setString(std::to_string(ship->get_health()));
      healthText.setCharacterSize(15);             // Setting size of characters
      healthText.setFillColor(sf::Color::Yellow);  // Set the text color

      // Set position above the ship
      sf::Vector2f position =
          ship->get_position();  // Create a method in Ship to get position
      healthText.setPosition(
          position.x, position.y - 30);  // Offset to display above the ship

      window.draw(healthText);
    }
  }

  Fleet& oppositeFleet =
      gameState.getOpponentFleet();  // get address of current fleet
  auto ships_in_opp_fleet = oppositeFleet.get_ships();

  for (const auto& ship : ships_in_opp_fleet) {
    if (ship->is_alive()) {
      sf::Text healthText;
      healthText.setFont(font);
      healthText.setString(std::to_string(ship->get_health()));
      healthText.setCharacterSize(15);             // Setting size of characters
      healthText.setFillColor(sf::Color::Yellow);  // Set the text color

      // Set position above the ship
      sf::Vector2f position =
          ship->get_position();  // Create a method in Ship to get position
      healthText.setPosition(
          position.x, position.y - 30);  // Offset to display above the ship

      window.draw(healthText);
    }
  }
}

void UIManager::drawIndexOfShipsWhileSelecting(sf::RenderWindow& window) {
  if (gameState.get_currentState() == SelectingAttackingShip) {
    Fleet& currentFleet =
        gameState.getCurrentFleet();  // get address of current fleet
    auto ships_in_fleet = currentFleet.get_ships();

    int i = 1;
    for (const auto& ship : ships_in_fleet) {
      if (ship->is_alive()) {
        sf::Text indexText;
        indexText.setFont(font);
        indexText.setCharacterSize(15);            // Setting size of characters
        indexText.setFillColor(sf::Color::Black);  // Set the text color

        // Create the string "[i]" using sstream
        std::ostringstream oss;
        oss << "[" << i << "]";          // Format the index
        indexText.setString(oss.str());  // Set the formatted string

        // Set position above the ship
        sf::Vector2f position =
            ship->get_position();  // Create a method in Ship to get position
        indexText.setPosition(
            position.x,
            position.y - 50);  // Offset to display below the ship

        window.draw(indexText);
      }
      i++;
    }
  }
}

void UIManager::drawIndexOfShipsWhileSelectingTarget(sf::RenderWindow& window) {
  if (gameState.get_currentState() == SelectingTargetShip) {
    Fleet& opponentFleet =
        gameState.getOpponentFleet();  // get address of current fleet
    auto ships_in__opp_fleet = opponentFleet.get_ships();

    int i = 1;
    for (const auto& ship : ships_in__opp_fleet) {
      if (ship->is_alive()) {
        sf::Text indexText;
        indexText.setFont(font);
        indexText.setCharacterSize(15);            // Setting size of characters
        indexText.setFillColor(sf::Color::Black);  // Set the text color

        // Create the string "[i]" using sstream
        std::ostringstream oss;
        oss << "[" << i << "]";          // Format the index
        indexText.setString(oss.str());  // Set the formatted string

        // Set position above the ship
        sf::Vector2f position =
            ship->get_position();  // Create a method in Ship to get position
        indexText.setPosition(
            position.x,
            position.y - 50);  // Offset to display below the ship

        window.draw(indexText);
      }
      i++;
    }
  }
}