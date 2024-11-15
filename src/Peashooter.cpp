#include "../inc/Peashooter.hpp"

Peashooter::Peashooter(short int col, short int row) :
    ShooterPlant(6, col, row, ProjectileType::PEA, 10, 1000) {
}

Peashooter::~Peashooter() {}

void Peashooter::action() {
    if (isAlive() && !onCooldown()) {
        shoot();
        updateLastShot();
    }
}

void Peashooter::shoot() {
    
}