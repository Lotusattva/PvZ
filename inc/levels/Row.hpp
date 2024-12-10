#ifndef ROW_HPP
#define ROW_HPP

#include "../plants/Plant.hpp"
#include "../zombies/Zombie.hpp"


// TODO: Figure out how to sync time across all actors

namespace PvZ {
    class Row {
    public:
        const short numCols;
        vector<Plant*> plants;
        vector<Zombie*>* zombies;
        time_point levelStart;

        Row(short numCols, vector<Zombie*>* zombies);
        ~Row();

        void action();
    };
}

#endif // ROW_HPP