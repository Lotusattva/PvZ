#ifndef ACTOR_HPP
#define ACTOR_HPP

#include "Stage.hpp"

namespace PvZ {

    /**
     * @brief Abstract base class for plants and zombies.
     */
    class Actor {
    private:
        short health;
        bool alive;

    public:

        Actor(short health, bool alive = true) : health{ health }, alive{ alive } {}
        Actor(const Actor&) = delete;
        Actor& operator=(const Actor&) = delete;
        virtual ~Actor() = default;

        /**
         * @brief actor performs an action
         *
         * @return true if the action was successful
         * @return false if the actor is dead
         */
        virtual bool action() = 0;

        /**
         * @brief actor takes damage
         *
         * @param damage
         */
        virtual void takeDamage(short damage) {
            health -= damage;
            if (health <= 0) {
                alive = false;
            }
        }

        bool isAlive() const { return alive; }

        virtual bool isZombie() const { return false; }
    };

}

#endif // ACTOR_HPP