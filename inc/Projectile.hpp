#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

enum class ProjectileType {
    PEA,
    SNOWPEA
};

class Projectile {
    private:
    const short int damage;
public:
    Projectile(short int damage) : damage(damage) {}
    virtual ~Projectile() = default;
};

Projectile* createProjectile(ProjectileType projectileType);

#endif // PROJECTILE_HPP