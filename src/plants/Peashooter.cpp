#include "plants/Peashooter.hpp"

namespace PvZ {
    Peashooter::Peashooter(short col) :
        ShooterPlant{ 6, col, Projectile::Type::PEA, 8, 1000ms } {}

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