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
        Vector2f position;

        enum class Type {
            PLANT,
            ZOMBIE,
            PROJECTILE,
            NULL_ACTOR
        };

    public:
        Actor(Vector2f position = { 0.f,0.f }, short health = 0) : health{ health }, position{ position } {}
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
        virtual bool inRange(const Actor* const other) const {
            return inRectangle(other->getCenter(), getHitbox());
        }

        const Vector2f& getPosition() const { return position; }
        virtual const Rectangle getHitbox() const = 0;
        virtual const Vector2f getCenter() const = 0;

        bool isAlive() const { return alive; }

        virtual Actor::Type getType() const = 0;
    };

}

#endif // ACTOR_HPP