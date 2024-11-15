#ifndef PEASHOOTER_HPP
#define PEASHOOTER_HPP

#include "ShooterPlant.hpp"

class Peashooter : public ShooterPlant {
public:
    Peashooter(short int col, short int row);
    ~Peashooter();

    virtual void action() override;
    virtual void shoot() override;
};

#endif // PEASHOOTER_HPP