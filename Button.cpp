
#include "Button.h"

Button::Button() {};

Button::Button(int size_x, int size_y, int pos_x, int pos_y,
               sf::Color buttonColor, std::string text, sf::Font& font) {
  // initialises the button rectangle properties
  this->color = buttonColor;
  this->shape.setSize(sf::Vector2f(size_x, size_y));
  this->shape.setPosition(pos_x, pos_y);
  this->shape.setFillColor(color);

  // initialises button label (this might be temporary if we decide to add
  // button sprites note: I dont think we will)
  label.setFont(font);  // this is another function below
  label.setString(text);
  label.setCharacterSize(15);            // size of text in all buttons
  label.setFillColor(sf::Color::White);  // textcolor for all buttons

  // place the label in the middle of the button
  // label has shape, so position can be
  // better handled NOTE: this doesnt work 100% properly but is close enough
  sf::FloatRect textRect = label.getLocalBounds();
  // set origin of text shape to middle
  label.setOrigin(textRect.width / 2, textRect.height / 2);
  // put text shape in middle of button shape
  label.setPosition(shape.getPosition().x + size_x / 2,
                    (shape.getPosition().y + size_y / 2) - textRect.height / 2);
};

// Please help I have no idea why when i try to get rid of repeating
// functionality it stops working in setFont, e.g. the setPosition
// HOWEVER it works fine so we may leave it
void Button::setFont(const sf::Font& font) {
  this->font = font;
  label.setFont(this->font);
  sf::FloatRect textRect = label.getLocalBounds();
  label.setOrigin(textRect.width / 2, textRect.height / 2);
  label.setPosition(shape.getPosition().x + shape.getSize().x / 2,
                    shape.getPosition().y + shape.getSize().y / 2);
}

void Button::draw(sf::RenderWindow& window) {  // draw
  window.draw(shape);                          // rectangle
  window.draw(label);                          // text
}

bool Button::isClickInButtonBounds(
    const sf::Vector2f& mousePos) {  // this is used in UIManager to check which
                                     // button was clicked
  if (shape.getGlobalBounds().contains(mousePos) == true) {
    return true;
  } else {
    return false;
  }
}

Button::~Button() {};