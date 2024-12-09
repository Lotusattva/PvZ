#include "plants/Peashooter.hpp"

Peashooter::Peashooter(sf::RenderWindow* window, short int col) :
    ShooterPlant(window, 6, col, ProjectileType::PEA, 8, 1000) { }

Peashooter::~Peashooter() { }

bool Peashooter::action() {
    if (!isAlive()) {
        return false;
    }
    return true;
}

void Peashooter::shoot() {

}