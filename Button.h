#include <SFML/Graphics.hpp>

#ifndef BUTTON_H
#define BUTTON_H

class Button {
 private:
  sf::RectangleShape shape;
  sf::Text label;  // all buttons assumed to need a label in center
  sf::Color color;
  sf::Font font;

 public:
  Button();
  Button(int size_x, int size_y, int pos_x, int pos_y, sf::Color color,
         std::string text, sf::Font& font);
  void setFont(const sf::Font& font);  // font isnt changed (const)
  bool isClickInButtonBounds(
      const sf::Vector2f& mousePosition);  // mouseposiiton isnt changed (const)
  virtual void buttonFunction(
      sf::RenderWindow&
          window) = 0;  // abstract, each button has its own function
  void draw(sf::RenderWindow& window);  // draw button

  virtual ~Button();  // deconstructor
};

#endif