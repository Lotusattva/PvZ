#ifndef ROW_HPP
#define ROW_HPP

#include <chrono>
#include <vector>
#include "../plants/Plant.hpp"
#include "../plants/NullPlant.hpp"
#include "../zombies/Zombie.hpp"
#include "../zombies/NullZombie.hpp"



using namespace std;
using clk = chrono::steady_clock;

class Row {
public:
    const short numCols;
    vector<Plant*> plants;
    vector<Zombie*>* zombies;
    chrono::time_point<clk> levelStart;

    Row(short numCols, vector<Zombie*>* zombies);
    ~Row();

    void action();
};

#endif // ROW_HPP