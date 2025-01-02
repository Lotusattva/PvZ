#include "zombies/RegularZombie.hpp"
#include "levels/Level.hpp"
#include <ranges>

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

    RegularZombie::RegularZombie(ms spawnTime, int row) : Zombie{ 10, movementInterval, attackInterval, spawnTime, row, hitbox, center } {}

    bool RegularZombie::action() {
        if (!spawned) {
            if (clk::now() >= spawnTime) {
                spawned = true;
            }
            return true;
        } else if (alive) {
            using namespace views;
            static auto notInRange = [this](const Actor* actor) { return !inRange(actor); };
            // check whether this zombie should attack
            if (auto inRangePlant = currentLevel->getActors() | filter(isAlivePlant) | drop_while(notInRange) | take(1);
                !inRangePlant.empty()) {
                // if a plant is in range, attack it
                drawSprite(attack.getFrame(), position);
                if (clk::now() - lastAttack >= attackInterval) {
                    lastAttack = clk::now();
                    inRangePlant.front()->takeDamage(1);
                }
            } else {
                // otherwise walk forward
                drawSprite(walk.getFrame(), position);
                if (clk::now() - lastMove >= movementInterval) {
                    position.x -= 1.f;
                    lastMove = clk::now();
                }
            }
            return true;
        } else {
            // if dead
            return false;
        }
    }

}