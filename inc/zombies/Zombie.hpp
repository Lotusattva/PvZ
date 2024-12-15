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
        ms movementSpeed;
        ms attackSpeed;
        time_point lastAttack;
        time_point lastMove;
        time_point lastSlowed;
        time_point spawnTime;
        bool slowed;
        bool spawned;

    public:
        Zombie(ushort health, ms movementSpeed, ms attackSpeed, ms spawnTime) :
            Actor(health), movementSpeed(movementSpeed), attackSpeed(attackSpeed), lastAttack(clk::now()),
            lastMove(clk::now()), lastSlowed(clk::now()), spawnTime(clk::now() + spawnTime), slowed(false), spawned(false) { }
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