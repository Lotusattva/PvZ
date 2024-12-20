#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

namespace PvZ {
    enum class ProjectileType {
        PEA,
        SNOWPEA
    };

    /**
     * @brief Base class for projectiles
     */
    class Projectile {
    private:
        const short damage;
    public:
        Projectile(short damage) : damage{ damage } {}
        Projectile(const Projectile&) = delete;
        Projectile(Projectile&&) = delete;
        virtual ~Projectile() = default;
    };

    Projectile* createProjectile(ProjectileType projectileType);
}

#endif // PROJECTILE_HPP