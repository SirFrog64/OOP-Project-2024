#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ship.h"
#include <vector>

using namespace std;

#ifndef FLEET_H
#define FLEET_H

class Fleet {
    private:
        int max_num_ships;
        vector<Ship*> fleet;

    public:
        Fleet();

        int get_num_ships();

        vector<Ship*> get_ships();

        void add_ship(Ship* ship);

        void remove_ship(Ship* ship);
};



#endif