#include "zombies/RegularZombie.hpp"

namespace PvZ {

    RegularZombie::Textures::Textures() {
        string root_path{ "res/img/zombie_" }, idle_path{ root_path + "idle/" }, walk_path{ root_path + "walk/" },
            attack_path{ root_path + "attack/" }, death_path{ root_path + "death/" }, ext{ ".png" };
        for (short i  = 1; i <= IDLE_FRAMES; ++i) {
            idle[i - 1].loadFromFile(idle_path + to_string(i) + ext);
        }
        for (short i  = 1; i <= WALK_FRAMES; ++i) {
            walk[i - 1].loadFromFile(walk_path + to_string(i) + ext);
        }
        for (short i  = 1; i <= ATTACK_FRAMES; ++i) {
            attack[i - 1].loadFromFile(attack_path + to_string(i) + ext);
        }
        for (short i  = 1; i <= DEATH_FRAMES; ++i) {
            death[i - 1].loadFromFile(death_path + to_string(i) + ext);
        }
    }

    RegularZombie::RegularZombie(ms spawnTime) : Zombie{ 10, 100ms, 100ms, spawnTime } {}

    bool RegularZombie::action() {
        
        // just testing the animation out for now
        Vector2f pos{ 200.f, 200.f };

        drawSprite(attackFrames.getFrame(pos)); 
        return true;
    }

    void RegularZombie::move() {
        return;
    }

    void RegularZombie::attack() {
        return;
    }

}