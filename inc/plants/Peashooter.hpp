#ifndef PEASHOOTER_HPP
#define PEASHOOTER_HPP

#include "ShooterPlant.hpp"

class Peashooter : public ShooterPlant {
public:
    Peashooter(RenderWindow* window, short int col, short int row);
    ~Peashooter();

    virtual bool action() override;
    virtual void shoot() override;
};

#endif // PEASHOOTER_HPP