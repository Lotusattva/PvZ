#ifndef PEASHOOTER_HPP
#define PEASHOOTER_HPP

#include "ShooterPlant.hpp"

namespace PvZ {
    class Peashooter : public ShooterPlant {
    public:
        Peashooter(short int col);
        ~Peashooter();

        bool action() override;
        void shoot() override;
    };
}

#endif // PEASHOOTER_HPP