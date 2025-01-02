#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "Actor.hpp"
#include "levels/Level.hpp"

namespace PvZ {

    /**
     * @brief Abstract base class for zombies
     */
    class Zombie : public Actor {
    protected:
        ms movementInterval, attackInterval; // TODO: maybe there's a better data type for this
        time_point lastAttack{ clk::now() }, lastMove{ clk::now() }, lastSlowed{ clk::now() }, spawnTime;
        bool slowed{ false }, spawned{ false };

    public:

        enum class Type {
            REGULAR,
            CONEHEAD,
            BUCKETHEAD,
            FLAG,
            POLEVAULT,
            FOOTBALL
        };

        Zombie(short health, ms movementInterval, ms attackInterval, ms spawnTime, int row, Vector2f hitbox, Vector2f center) :
            Actor{ health, { 870.f, row * Level::cellHeight + Level::gridOrigin.y }, hitbox, center }, movementInterval{ movementInterval },
            attackInterval{ attackInterval }, spawnTime{ clk::now() + spawnTime } {}
        Zombie(const Zombie&) = delete;
        Zombie(Zombie&&) = delete;
        virtual ~Zombie() = default;

        Actor::Type getType() const override { return Actor::Type::ZOMBIE; }
    };

}

#endif // ZOMBIE_HPP