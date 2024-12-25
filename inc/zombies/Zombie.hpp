#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "Actor.hpp"

namespace PvZ {

    enum class ZombieType {
        REGULAR,
        CONEHEAD,
        BUCKETHEAD,
        FLAG,
        POLEVAULT,
        FOOTBALL
    };

    /**
     * @brief Abstract base class for zombies
     */
    class Zombie : public Actor {
    protected:
        ms movementSpeed, attackSpeed; // TODO: maybe there's a better data type for this
        time_point lastAttack{ clk::now() }, lastMove{ clk::now() }, lastSlowed{ clk::now() }, spawnTime;
        bool slowed{ false }, spawned{ false };
        int x{ 900 }, y;
        static inline const int cellHeight{ 96 }, offset{ 80 };

    public:
        Zombie(short health, ms movementSpeed, ms attackSpeed, ms spawnTime, int col) :
            Actor{ health }, movementSpeed{ movementSpeed }, attackSpeed{ attackSpeed }, spawnTime{ clk::now() + spawnTime }, y{ col * cellHeight + offset } {}
        Zombie(const Zombie&) = delete;
        Zombie& operator=(const Zombie&) = delete;
        virtual ~Zombie() = default;

        Actor::Type getType() const override { return Actor::Type::ZOMBIE; }
    };

}

#endif // ZOMBIE_HPP