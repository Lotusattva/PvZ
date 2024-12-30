#include "zombies/RegularZombie.hpp"

namespace PvZ {

    RegularZombie::Textures::Textures() {
        string root_path{ RES_PATH + "img/zombie_" }, idle_path{ root_path + "idle/" }, walk_path{ root_path + "walk/" },
            attack_path{ root_path + "attack/" }, death_path{ root_path + "death/" }, ext{ ".png" };
        idleTextures.reserve(IDLE_FRAMES);
        for (auto i : range(1, IDLE_FRAMES + 1)) {
            Texture tex{ idle_path + to_string(i) + ext };
            idleTextures.push_back(tex);
        }
        walkTextures.reserve(WALK_FRAMES);
        for (auto i : range(1, WALK_FRAMES + 1)) {
            Texture tex{ walk_path + to_string(i) + ext };
            walkTextures.push_back(tex);
        }
        attackTextures.reserve(ATTACK_FRAMES);
        for (auto i : range(1, ATTACK_FRAMES + 1)) {
            Texture tex{ attack_path + to_string(i) + ext };
            attackTextures.push_back(tex);
        }
        deathTextures.reserve(DEATH_FRAMES);
        for (auto i : range(1, DEATH_FRAMES + 1)) {
            Texture tex{ death_path + to_string(i) + ext };
            deathTextures.push_back(tex);
        }
    }

    RegularZombie::RegularZombie(ms spawnTime, int row) : Zombie{ 10, RegZombMvmtIntrvl, RegZombAttkIntrvl, spawnTime, row, RegZombHitbox } {}

    bool RegularZombie::action() {
        if (!spawned) {
            if (clk::now() >= spawnTime) {
                spawned = true;
                drawSprite(walk.getFrame(), position);
                return true;
            } else {
                return true;
            }
        } else {
            if (clk::now() - lastMove >= movementInterval) {
                position.x -= 1.f;
                lastMove = clk::now();
            }
            drawSprite(walk.getFrame(), position);
        }
        return true;
    }

}