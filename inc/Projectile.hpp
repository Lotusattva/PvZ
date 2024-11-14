#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

enum class ProjectileType {
    NONE,
    PEA,
    SNOWPEA
};

class Projectile {
    private:
    const short int damage;
protected:
    Projectile(short int damage) : damage(damage) {}
    virtual ~Projectile() = 0 {}
};

Projectile* createProjectile(ProjectileType projectileType);

#endif // PROJECTILE_HPP