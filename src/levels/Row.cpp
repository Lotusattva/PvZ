#include "../../inc/levels/Row.hpp"

Row::Row(short numCols, vector<Zombie*>* zombies, vector<std::chrono::milliseconds>* zombieSpawnTimes) :
    numCols(numCols), plants(numCols), zombies(zombies), zombieSpawnTimes(zombieSpawnTimes) {
    for (size_t col = 0; col < numCols; col++) {
        plants.push_back(new NullPlant());
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
    delete zombieSpawnTimes;
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