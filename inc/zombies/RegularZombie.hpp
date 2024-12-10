#ifndef REGULARZOMBIE_HPP
#define REGULARZOMBIE_HPP

#include "Zombie.hpp"

namespace PvZ {
    class RegularZombie : public Zombie { 
        public:
        RegularZombie(ms spawnTime);
        ~RegularZombie() = default;
        bool action() override;
        void move() override;
        void attack() override;
    };
}

#endif // REGULARZOMBIE_HPP