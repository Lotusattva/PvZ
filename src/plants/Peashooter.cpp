#include "plants/Peashooter.hpp"

namespace PvZ {
    Peashooter::Peashooter(short col) :
        ShooterPlant(6, col, ProjectileType::PEA, 8, 1000) { }

    Peashooter::~Peashooter() { }

    bool Peashooter::action() {
        if (!isAlive()) {
            return false;
        }
        return true;
    }

    void Peashooter::shoot() {

    }
}