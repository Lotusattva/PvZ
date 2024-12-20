#include "zombies/RegularZombie.hpp"

namespace PvZ {

    RegularZombie::Textures::Textures() {
        string root_path{ "res/img/zombie_" }, idle_path{ root_path + "idle/" }, walk_path{ root_path + "walk/" },
            attack_path{ root_path + "attack/" }, death_path{ root_path + "death/" }, ext{ ".png" };
        for (short i : range(1, IDLE_FRAMES + 1)) {
            idle[i].loadFromFile(idle_path + to_string(i) + ext);
        }
        for (short i : range(1, WALK_FRAMES + 1)) {
            walk[i].loadFromFile(walk_path + to_string(i) + ext);
        }
        for (short i : range(1, ATTACK_FRAMES + 1)) {
            attack[i].loadFromFile(attack_path + to_string(i) + ext);
        }
        for (short i : range(1, DEATH_FRAMES + 1)) {
            death[i].loadFromFile(death_path + to_string(i) + ext);
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