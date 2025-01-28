#include "Cabbage-pult.hpp"
#include <iostream>

CabbagePult::CabbagePult(sf::Texture& texture, float x, float y, int health, int attackPower)
    : health(health), attackPower(attackPower) {
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

void CabbagePult::attack(Zombie& zombie) {
    zombie.health -= attackPower;
    std::cout << "Cabbage-Pult attacks Zombie for " << attackPower << " damage!\n";

    if (zombie.health <= 0) {
        std::cout << "Zombie defeated by Cabbage-Pult!\n";
    }
}
