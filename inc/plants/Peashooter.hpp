#ifndef PEASHOOTER_HPP
#define PEASHOOTER_HPP

#include "ShooterPlant.hpp"

class Peashooter : public ShooterPlant {
public:
    Peashooter(RenderWindow* window, short int col);
    ~Peashooter();

    bool action() override;
    void shoot() override;
};

#endif // PEASHOOTER_HPP