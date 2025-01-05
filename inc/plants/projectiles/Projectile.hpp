#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "Actor.hpp"

namespace PvZ {


    /**
     * @brief Base class for projectiles
     */
    class Projectile : public Actor {
    protected:
        const short damage;
    public:
        enum class Type {
            PEA
        };

        Projectile(Vector2f& position, short damage) : Actor{ position }, damage{ damage } {}
        Projectile(const Projectile&) = delete;
        Projectile(Projectile&&) = delete;
        virtual ~Projectile() = default;

        void takeDamage(short damage) override { return; }

        Actor::Type getType() const override { return Actor::Type::PROJECTILE; }

        static Projectile* create(Projectile::Type projectileType, Vector2f& position);
    };


}

#endif // PROJECTILE_HPP