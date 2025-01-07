#include "plants/projectiles/Pea.hpp"
#include "levels/Level.hpp"

namespace PvZ {
    bool Pea::inRange(const Actor* const other) const {
        return inRectangle(getCenter(), other->getHitbox());
    }

    bool Pea::action() {
        // check if the pea is still on screen
        if (position.x > 900.f) {
            return false;
        }
        // check if the pea is in range of a zombie
        static auto notInRange = [this](Actor* actor) { return !inRange(actor); };
        using namespace views;
        if (auto inRangeZombie = currentLevel->getActors() | filter(isAliveZombie) | drop_while(notInRange) | take(1);
                !inRangeZombie.empty()) {
                    inRangeZombie.front()->takeDamage(damage);
                    return false;
        } else {
            // move the pea forward
            position.x += 3.f;
            drawSprite(sprite, position);
            return true;
        }
    }

    const Rectangle Pea::getHitbox() const {
        return { position, { 24.f, 24.f } };
    }

    const Vector2f Pea::getCenter() const {
        static const Vector2f centerOffset{ 12.f, 12.f };
        return position + centerOffset;
    }
}