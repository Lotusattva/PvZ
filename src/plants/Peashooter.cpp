#include "plants/Peashooter.hpp"

namespace PvZ {
    Peashooter::Peashooter(short row) :
        ShooterPlant{ 6, row, Projectile::Type::PEA, 8, 1000ms } {}

    Peashooter::~Peashooter() {}

    bool Peashooter::action() {
        if (!isAlive()) {
            return false;
        }
        return true;
    }

    void Peashooter::shoot() {

    }
}