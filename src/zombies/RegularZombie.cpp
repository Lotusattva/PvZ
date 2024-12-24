#include "zombies/RegularZombie.hpp"

namespace PvZ {

    RegularZombie::Textures::Textures() {
        string root_path{ "res/img/zombie_" }, idle_path{ root_path + "idle/" }, walk_path{ root_path + "walk/" },
            attack_path{ root_path + "attack/" }, death_path{ root_path + "death/" }, ext{ ".png" };
        idle.reserve(IDLE_FRAMES);
        for (short i : range(1, IDLE_FRAMES + 1)) {
            idle.push_back(Texture{ idle_path + to_string(i) + ext });
        }
        walk.reserve(WALK_FRAMES);
        for (short i : range(1, WALK_FRAMES + 1)) {
            walk.push_back(Texture{ walk_path + to_string(i) + ext });
        }
        attack.reserve(ATTACK_FRAMES);
        for (short i : range(1, ATTACK_FRAMES + 1)) {
            attack.push_back(Texture{ attack_path + to_string(i) + ext });
        }
        death.reserve(DEATH_FRAMES);
        for (short i : range(1, DEATH_FRAMES + 1)) {
            death.push_back(Texture{ death_path + to_string(i) + ext });
        }
    }

    RegularZombie::RegularZombie(ms spawnTime) : Zombie{ 10, 100ms, 100ms, spawnTime } {}

    bool RegularZombie::action() {

        // just testing the animation out for now
        Vector2f pos{ 200.f, 200.f };

        drawSprite(walk.getFrame(pos));
        return true;
    }

}