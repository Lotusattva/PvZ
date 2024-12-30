#ifndef ACTOR_HPP
#define ACTOR_HPP

#include "Stage.hpp"

namespace PvZ {

    /**
     * @brief Abstract base class for plants and zombies.
     */
    class Actor {
    protected:
        short health;
        bool alive{ true };
        Vector2f position, hitbox;

        enum class Type {
            PLANT,
            ZOMBIE,
            PROJECTILE,
            NULL_ACTOR
        };

    public:
        Actor(short health = 0, Vector2f position = { 0.f,0.f }, Vector2f hitbox = { 0.f,0.f }) :
            health{ health }, position{ position }, hitbox{ hitbox } {}
        Actor(const Actor&) = delete;
        Actor(Actor&&) = delete;
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

        virtual bool collidesWith(const Actor&) const = 0;

        bool isAlive() const { return alive; }

        virtual Actor::Type getType() const = 0;
    };

}

#endif // ACTOR_HPP