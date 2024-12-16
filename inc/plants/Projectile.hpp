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
        const ushort damage;
    public:
        Projectile(ushort damage) : damage{ damage } {}
        virtual ~Projectile() = default;
    };

    Projectile* createProjectile(ProjectileType projectileType);
}

#endif // PROJECTILE_HPP