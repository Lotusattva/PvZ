#include "zombies/RegularZombie.hpp"

namespace PvZ {

    const RegularZombie::Sprites RegularZombie::sprites{ Sprites() };

    RegularZombie::Sprites::Sprites() {
        for (short i : range(1, IDLE_FRAMES + 1)) {
            idle[i].loadFromFile("res/img/zombie_idle/" + to_string(i) + ".png");
        }
        for (short i : range(1, WALK_FRAMES + 1)) {
            walk[i].loadFromFile("res/img/zombie_walk/" + to_string(i) + ".png");
        }
        for (short i : range(1, ATTACK_FRAMES + 1)) {
            attack[i].loadFromFile("res/img/zombie_attack/" + to_string(i) + ".png");
        }
        for (short i : range(1, DEATH_FRAMES + 1)) {
            death[i].loadFromFile("res/img/zombie_death/" + to_string(i) + ".png");
        }
    }

    RegularZombie::RegularZombie(ms spawnTime) : Zombie{ 10, 100ms, 100ms, spawnTime } {}

    bool RegularZombie::action() {
        return true;
    }

    void RegularZombie::move() {
        return;
    }

    void RegularZombie::attack() {
        return;
    }

}