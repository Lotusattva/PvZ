#ifndef NULLZOMBIE_HPP
#define NULLZOMBIE_HPP

#include "Zombie.hpp"

class NullZombie : public Zombie {
public:
    NullZombie() : Zombie(nullptr, 0, 0ms, 0ms, 0ms) { }
    ~NullZombie() = default;

    bool action() override { return true; }
    void move() override { }
    void attack() override { }
};

#endif // NULLZOMBIE_HPP