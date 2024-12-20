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
    private:
        ms movementSpeed, attackSpeed; // TODO: maybe there's a better data type for this
        time_point lastAttack{ clk::now() }, lastMove{ clk::now() }, lastSlowed{ clk::now() }, spawnTime;
        bool slowed{ false }, spawned{ false };
        Vector2f position;

    public:
        Zombie(short health, ms movementSpeed, ms attackSpeed, ms spawnTime) :
            Actor{ health }, movementSpeed{ movementSpeed }, attackSpeed{ attackSpeed }, spawnTime{ clk::now() + spawnTime } {}
        Zombie(const Zombie&) = delete;
        Zombie& operator=(const Zombie&) = delete;
        virtual ~Zombie() = default;

        /**
         * @brief zombie moves
         */
        virtual void move() = 0;

        /**
         * @brief zombie attacks
         */
        virtual void attack() = 0;

        bool isZombie() const override { return true; }
    };

}

#endif // ZOMBIE_HPP