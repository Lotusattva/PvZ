#include "zombies/RegularZombie.hpp"

namespace PvZ {

    RegularZombie::Sprites::Sprites() {
        string root_path{ "res/img/zombie_" }, idle_path{ root_path + "idle/" }, walk_path{ root_path + "walk/" },
            attack_path{ root_path + "attack/" }, death_path{ root_path + "death/" }, ext{ ".png" };
        idleTextures.reserve(IDLE_FRAMES);
        for (short i : range(1, IDLE_FRAMES + 1)) {
            idleTextures.push_back(Texture{ idle_path + to_string(i) + ext });
        }
        walkTextures.reserve(WALK_FRAMES);
        for (short i : range(1, WALK_FRAMES + 1)) {
            walkTextures.push_back(Texture{ walk_path + to_string(i) + ext });
        }
        attackTextures.reserve(ATTACK_FRAMES);
        for (short i : range(1, ATTACK_FRAMES + 1)) {
            attackTextures.push_back(Texture{ attack_path + to_string(i) + ext });
        }
        deathTextures.reserve(DEATH_FRAMES);
        for (short i : range(1, DEATH_FRAMES + 1)) {
            deathTextures.push_back(Texture{ death_path + to_string(i) + ext });
        }
    }

    RegularZombie::RegularZombie(ms spawnTime, int col) : Zombie{ 10, 10ms, 500ms, spawnTime, col } {}

    bool RegularZombie::action() {
        if (!spawned) {
            if (clk::now() >= spawnTime) {
                spawned = true;
                drawSprite(walk.getFrame(), { x, y });
                return true;
            } else {
                return true;
            }
        } else {
            if (clk::now() - lastMove >= movementSpeed) {
                x -= 5;
                lastMove = clk::now();
            }
            drawSprite(walk.getFrame(), { x, y });
        }
        return true;
    }

}