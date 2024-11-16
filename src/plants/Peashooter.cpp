#include "../../inc/plants/Peashooter.hpp"

Peashooter::Peashooter(sf::RenderWindow* window, short int col, short int row) :
    ShooterPlant(window, 6, col, row, ProjectileType::PEA, 8, 1000) {
}

Peashooter::~Peashooter() {}

bool Peashooter::action() {
    if (!isAlive()) {
        return false;
    }
    return true;
}

void Peashooter::shoot() {

}