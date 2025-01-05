#include "plants/projectiles/Pea.hpp"

namespace PvZ {
    bool Pea::inRange(const Actor* const other) const {
        return inRectangle(getCenter(), other->getHitbox());
    }
}