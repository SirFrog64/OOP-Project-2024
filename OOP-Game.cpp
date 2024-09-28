#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Ship.h"
#include "Frigate.h"

using namespace sf;

class Boats_N_Battles {
    private:
        sf::RenderWindow* window;
        int size;
        std::string title;
    
    public:
        Boats_N_Battles(int size, std::string title) {
            window = new sf::RenderWindow(sf::VideoMode(2*size, size), title);
        }

        void run_game() {

            while(window->isOpen()) {
                Event e;

                while(window->pollEvent(e)) {
                    if(e.type == Event::Closed) {
                        window->close();
                    }
                }

                window->clear(sf::Color(135, 206, 235));
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