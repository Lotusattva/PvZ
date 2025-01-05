#include "plants/ShooterPlant.hpp"

namespace PvZ {
    bool ShooterPlant::action() {
        if (alive) {
            drawSprite(getFrames().getFrame(), position);
            using namespace views;
            static auto notInRange = [this](Actor* actor) { return !inRange(actor); };
            // check whether this peashooter should attack
            if (auto inRangeZombie = currentLevel->getActors() | filter(isZombie) | drop_while(notInRange) | take(1);
                !inRangeZombie.empty()) {
                // if a zombie is in range, attack it
                if (clk::now() - lastAttack >= attackInterval) {
                    lastAttack = clk::now();
                    // shoot();
                }
            }
            // otherwise, do nothing
            return true;
        } else {
            return false;
        }
    }
}