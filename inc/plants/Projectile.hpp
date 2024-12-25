#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

namespace PvZ {


    /**
     * @brief Base class for projectiles
     */
    class Projectile : public Actor {
    private:
        const short damage;
    public:
        enum class Type {
            PEA,
            SNOWPEA
        };

        Projectile(short damage) : damage{ damage } {}
        Projectile(const Projectile&) = delete;
        Projectile(Projectile&&) = delete;
        virtual ~Projectile() = default;

        void takeDamage(short damage) override { return; }

        Actor::Type getType() const override { return Actor::Type::PROJECTILE; }
    };

    Projectile* createProjectile(Projectile::Type projectileType);
}

#endif // PROJECTILE_HPP