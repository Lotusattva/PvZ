#ifndef ROW_HPP
#define ROW_HPP

#include <SFML/Graphics.hpp>
#include <chrono>
#include <vector>
#include "../plants/Plant.hpp"
#include "../plants/NullPlant.hpp"
#include "../zombies/Zombie.hpp"

using namespace sf;
using namespace std::chrono;
using namespace std;

class Row {
private:
    RenderWindow* window;
    const short numCols;
    vector<Plant*> plants;
    vector<Zombie*>* zombies;
    vector<std::chrono::milliseconds>* zombieSpawnTimes;
public:
    Row(RenderWindow* window, short numCols, vector<Zombie*>* zombies, vector<std::chrono::milliseconds>* zombieSpawnTimes) :
        window(window), numCols(numCols), plants(numCols), zombies(zombies), zombieSpawnTimes(zombieSpawnTimes) {
        for (short col = 0; col < numCols; col++) {
            plants.assign(col, new NullPlant());
        }
    }
    ~Row() {
        for (auto plant : plants) {
            delete plant;
        }
        for (auto zombie : *zombies) {
            delete zombie;
        }
        delete zombies;
        delete zombieSpawnTimes;
    }
};

#endif // ROW_HPP