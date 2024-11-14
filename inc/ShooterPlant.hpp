#ifndef SHOOTER_PLANT_HPP
#define SHOOTER_PLANT_HPP

#include "Plant.hpp"

class ShooterPlant : public Plant {
private:
    const short int range;
    const short int cooldown;
public:
    ShooterPlant(short int health, short int col, short int row, short int range, short int cooldown) :
        Plant(health, col, row), range(range), cooldown(cooldown) {}
    virtual ~ShooterPlant() = 0 {}

    virtual void shoot();
};

#endif // SHOOTER_PLANT_HPP