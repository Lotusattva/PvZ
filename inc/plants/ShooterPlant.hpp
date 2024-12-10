#ifndef SHOOTER_PLANT_HPP
#define SHOOTER_PLANT_HPP

#include "Plant.hpp"
#include "Projectile.hpp"

namespace PvZ {
    class ShooterPlant : public Plant {
    private:
        const ProjectileType projectileType;
        const short range;
        const ms cooldown;
        time_point lastShot;
    public:
        ShooterPlant(short int health, short int col, ProjectileType projectileType, short int range, int cooldown) :
            Plant(health, col), projectileType(projectileType), range(range), cooldown(cooldown), lastShot(clk::now()) { }
        virtual ~ShooterPlant() = default;

        virtual void shoot() = 0;

        bool withInRange(Actor* actor) const;
        short int getRange() const { return range; }
        bool onCooldown() const { return clk::now() - lastShot < cooldown; }
        void updateLastShot() { lastShot = clk::now(); }
    };
}

#endif // SHOOTER_PLANT_HPP