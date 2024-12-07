#ifndef ROW_HPP
#define ROW_HPP

#include <chrono>
#include <vector>
#include "../plants/Plant.hpp"
#include "../plants/NullPlant.hpp"
#include "../zombies/Zombie.hpp"
#include "../zombies/NullZombie.hpp"

using namespace std::chrono;
using namespace std;

class Row {
public:
    const short numCols;
    vector<Plant*> plants;
    vector<Zombie*>* zombies;
    vector<std::chrono::milliseconds>* zombieSpawnTimes;

    Row(short numCols, vector<Zombie*>* zombies, vector<std::chrono::milliseconds>* zombieSpawnTimes);
    ~Row();

    void action();
};

#endif // ROW_HPP