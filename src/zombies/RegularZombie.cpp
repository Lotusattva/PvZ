#include "zombies/RegularZombie.hpp"

namespace PvZ {

    RegularZombie::Sprites::Sprites() {
        string root_path{ RES_PATH + "img/zombie_" }, idle_path{ root_path + "idle/" }, walk_path{ root_path + "walk/" },
            attack_path{ root_path + "attack/" }, death_path{ root_path + "death/" }, ext{ ".png" };
        idleTextures.reserve(IDLE_FRAMES);
        idleSprites.reserve(IDLE_FRAMES);
        for (auto i : range(1, IDLE_FRAMES + 1)) {
            Texture tex{ idle_path + to_string(i) + ext };
            idleTextures.push_back(tex);
            idleSprites.push_back(Sprite{ tex });
        }
        walkTextures.reserve(WALK_FRAMES);
        walkSprites.reserve(WALK_FRAMES);
        for (auto i : range(1, WALK_FRAMES + 1)) {
            Texture tex{ walk_path + to_string(i) + ext };
            walkTextures.push_back(tex);
            walkSprites.push_back(Sprite{ tex });
        }
        attackTextures.reserve(ATTACK_FRAMES);
        attackSprites.reserve(ATTACK_FRAMES);
        for (auto i : range(1, ATTACK_FRAMES + 1)) {
            Texture tex{ attack_path + to_string(i) + ext };
            attackTextures.push_back(tex);
            attackSprites.push_back(Sprite{ tex });
        }
        deathTextures.reserve(DEATH_FRAMES);
        deathSprites.reserve(DEATH_FRAMES);
        for (auto i : range(1, DEATH_FRAMES + 1)) {
            Texture tex{ death_path + to_string(i) + ext };
            deathTextures.push_back(tex);
            deathSprites.push_back(Sprite{ tex });
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