#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

enum class ProjectileType {
    PEA,
    SNOWPEA
};

class Projectile {
private:
    const short int damage;
    RenderWindow* window;
public:
    Projectile(RenderWindow* window, short int damage) : window(window), damage(damage) {}
    virtual ~Projectile() = default;
};

Projectile* createProjectile(RenderWindow* window, ProjectileType projectileType);

#endif // PROJECTILE_HPP