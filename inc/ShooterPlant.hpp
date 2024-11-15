#ifndef SHOOTER_PLANT_HPP
#define SHOOTER_PLANT_HPP

#include <chrono>
#include "Plant.hpp"
#include "Projectile.hpp"

using namespace std::chrono;

class ShooterPlant : public Plant {
private:
    const ProjectileType projectileType;
    const short int range;
    const milliseconds cooldown;
    time_point<steady_clock> lastShot;
public:
    ShooterPlant(short int health, short int col, short int row, ProjectileType projectileType, short int range, int cooldown) :
        Plant(health, col, row), projectileType(projectileType), range(range), cooldown(cooldown), lastShot(steady_clock::now()) {
    }
    virtual ~ShooterPlant() = default;

    virtual void shoot() = 0;

    bool withInRange(Actor* actor) const;
    short int getRange() const { return range; }
    bool onCooldown() const {
        return duration_cast<milliseconds>(steady_clock::now() - lastShot).count() < cooldown.count();
    }
    void updateLastShot() { lastShot = steady_clock::now(); }
};

#endif // SHOOTER_PLANT_HPP