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
        ms movementInterval, attackInterval; // TODO: maybe there's a better data type for this
        time_point lastAttack{ clk::now() }, lastMove{ clk::now() }, lastSlowed{ clk::now() }, spawnTime;
        bool slowed{ false }, spawned{ false };
        float x{ 900.f }, y;
        static inline const float cellHeight{ 96.f }, offset{ 80.f };

    public:
        Zombie(short health, ms movementInterval, ms attackInterval, ms spawnTime, int col) :
            Actor{ health }, movementInterval{ movementInterval }, attackInterval{ attackInterval }, spawnTime{ clk::now() + spawnTime }, y{ col * cellHeight + offset } {}
        Zombie(const Zombie&) = delete;
        Zombie& operator=(const Zombie&) = delete;
        virtual ~Zombie() = default;

        Actor::Type getType() const override { return Actor::Type::ZOMBIE; }
    };

}

#endif // ZOMBIE_HPP