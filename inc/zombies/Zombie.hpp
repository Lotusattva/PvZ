#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "../Actor.hpp"
#include <chrono>

using namespace std;
using ms = chrono::milliseconds;
using clk = chrono::steady_clock;

enum class ZombieType {
    NORMAL,
    CONEHEAD,
    BUCKETHEAD,
    FLAG,
    POLEVAULT,
    FOOTBALL
};

class Zombie : public Actor {
private:
    ms movementSpeed;
    ms attackSpeed;
    chrono::time_point<clk> lastAttack;
    chrono::time_point<clk> lastMove;
    chrono::time_point<clk> lastSlowed;
    chrono::time_point<clk> spawnTime;
    bool slowed;
    bool spawned;

public:
    Zombie(RenderWindow* window, short int health, ms movementSpeed, ms attackSpeed, ms spawnTime) :
        Actor(window, health), movementSpeed(movementSpeed), attackSpeed(attackSpeed), lastAttack(clk::now()),
        lastMove(clk::now()), lastSlowed(clk::now()), spawnTime(clk::now() + spawnTime), slowed(false), spawned(false) { }
    virtual ~Zombie() = default;

    virtual void move() = 0;
    virtual void attack() = 0;
};

#endif // ZOMBIE_HPP