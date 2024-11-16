#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "Actor.hpp"
#include <chrono>

using namespace std::chrono;
using namespace sf;

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
    std::chrono::milliseconds movementSpeed;
    std::chrono::milliseconds attackSpeed;
    time_point<steady_clock> lastAttack;
    bool slowed;

public:
    Zombie(RenderWindow* window, short int health, std::chrono::milliseconds movementSpeed, std::chrono::milliseconds attackSpeed) :
        Actor(window, health), movementSpeed(movementSpeed), attackSpeed(attackSpeed), lastAttack(steady_clock::now()), slowed(false) {
    }
    virtual ~Zombie() = default;

    virtual void move() = 0;
    virtual void attack() = 0;
};

#endif // ZOMBIE_HPP