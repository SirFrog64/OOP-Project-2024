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
        }

        void run_game() {

            // Create a Frigate
            Ship* fr1 = new Frigate(20, 100, 80, 1, 60, window);
            fr1->render(50, 150);
            fr1->set_position(50, 150);

            while(window->isOpen()) {
                Event event;

                while(window->pollEvent(event)) {
                    if(event.type == Event::Closed) {
                        window->close();
                    }
                }

                window->clear(sf::Color(135, 206, 235));
                fr1->draw();
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