#ifndef SUNPLANT_HPP
#define SUNPLANT_HPP

#include "Plant.hpp"

class SunPlant : public Plant {
private:
    const short int sunProduction;
    const short int cooldown;
public:
    SunPlant(sf::RenderWindow* window, short int health, short int col, short int row, short int sunProduction, short int cooldown) :
        Plant(window, health, col, row), sunProduction(sunProduction), cooldown(cooldown) {}
    virtual ~SunPlant() = 0 {}

    virtual void produceSun();
};

#endif // SUNPLANT_HPP