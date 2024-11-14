#ifndef SHOOTER_PLANT_HPP
#define SHOOTER_PLANT_HPP

#include "Plant.hpp"
#include "Projectile.hpp"

class ShooterPlant : public Plant {
private:
    const ProjectileType projectileType;
    const short int range;
    const short int cooldown;
public:
    ShooterPlant(short int health, short int col, short int row, ProjectileType projectileType, short int range, short int cooldown) :
        Plant(health, col, row), projectileType(projectileType), range(range), cooldown(cooldown) {}
    virtual ~ShooterPlant() = 0 {}

    virtual void shoot();
};

#endif // SHOOTER_PLANT_HPP