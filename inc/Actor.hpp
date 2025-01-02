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
        Vector2f position, hitbox, center;

        enum class Type {
            PLANT,
            ZOMBIE,
            PROJECTILE,
            NULL_ACTOR
        };

    public:
        Actor(short health = 0, Vector2f position = { 0.f,0.f }, Vector2f hitbox = { 0.f,0.f }, Vector2f center = { 0.f,0.f }) :
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

        /**
         * @brief checks whether the other actor is in range of this actor
         *
         * @param other
         * @return true if the other actor is in range
         */
        virtual bool inRange(const Actor* other) const {
            return inRectangle(other->center, position, hitbox) || inRectangle(center, other->position, other->hitbox);
        }

        bool isAlive() const { return alive; }

        virtual Actor::Type getType() const = 0;
    };

}

#endif // ACTOR_HPP