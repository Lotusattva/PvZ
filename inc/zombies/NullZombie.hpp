#ifndef NULLZOMBIE_HPP
#define NULLZOMBIE_HPP

#include "Zombie.hpp"

namespace PvZ {

    class NullZombie : public Zombie {
    public:
        NullZombie() : Zombie(0, 0ms, 0ms, 0ms) { }
        ~NullZombie() = default;

        bool action() override { return true; }
        void move() override { }
        void attack() override { }
    };
}

#endif // NULLZOMBIE_HPP