#include "levels/Row.hpp"
#include "plants/NullPlant.hpp"
#include "zombies/NullZombie.hpp"

namespace PvZ {
    Row::Row(short numCols, vector<Zombie*>* zombies) :
        numCols(numCols), plants(numCols), zombies(zombies), levelStart(clk::now()) {
        for (size_t col = 0; col < numCols; col++) {
            plants[col] = new NullPlant();
        }
    }

    Row::~Row() {
        for (auto plant : plants) {
            delete plant;
        }
        for (auto zombie : *zombies) {
            delete zombie;
        }
        delete zombies;
    }

    void Row::action() {
        for (auto plant : plants) {
            if (!plant->action()) {
                delete plant;
                plant = new NullPlant();
            }
        }

        for (auto zombie : *zombies) {
            if (!zombie->action()) {
                delete zombie;
                zombie = new NullZombie();
            }
        }
    }
}