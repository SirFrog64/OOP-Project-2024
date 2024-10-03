#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Ship.h"
#include "Frigate.h"


using namespace sf;


class Boats_N_Battles {
    private:
        sf::RenderWindow* window;

    public:
        Boats_N_Battles(int size, std::string title) {
            window = new sf::RenderWindow(sf::VideoMode(2*size, size), title);
            window->setVerticalSyncEnabled(true);
            window->setFramerateLimit(60);
        }

        void run_game() {

            // Create a Frigate
            Ship* fr1 = new Frigate(20, 100, 80, 1, 60, window);
            fr1->render(50, 150);
            fr1->set_position(50, 150);

            // Define a rectangle shape for bounds
            sf::RectangleShape button(sf::Vector2f(200, 100));
            button.setPosition(300, 250); // Position it in the window
            button.setFillColor(sf::Color::Green);

            while(window->isOpen()) {
                Event event;

                while(window->pollEvent(event)) {
                    if(event.type == Event::Closed) {
                        window->close();
                    }
                }

                if (Keyboard::isKeyPressed(Keyboard::A)) {
                    fr1->remove_ship(fr1);
                }

                Vector2i mousePos = Mouse::getPosition(*window);
                    
                // Check if mouse position is within the bounds of the button
                if (button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    // Mouse is within the button bounds
                    fr1->remove_ship(fr1);
                }

                window->clear(sf::Color(135, 206, 235));
                fr1->draw();
                window->draw(button);
                window->display();   
            }
        }
        ~Boats_N_Battles() {
            delete window;
        }
};


int main() {
    Boats_N_Battles b1(1000, "Boats 'n Battles");

    b1.run_game();

    return 0;
}
