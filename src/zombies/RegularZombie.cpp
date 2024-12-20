#include "zombies/RegularZombie.hpp"

namespace PvZ {

    RegularZombie::Textures::Textures() {
        string path{ "res/img/zombie_idle/" }, ext{ ".png" };
        for (short i : range(1, IDLE_FRAMES + 1)) {
            idle[i].loadFromFile(path + to_string(i) + ext);
        }
        for (short i : range(1, WALK_FRAMES + 1)) {
            walk[i].loadFromFile(path + to_string(i) + ext);
        }
        for (short i : range(1, ATTACK_FRAMES + 1)) {
            attack[i].loadFromFile(path + to_string(i) + ext);
        }
        for (short i : range(1, DEATH_FRAMES + 1)) {
            death[i].loadFromFile(path + to_string(i) + ext);
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