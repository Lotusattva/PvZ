#include "plants/projectiles/Projectile.hpp"
#include "plants/projectiles/Pea.hpp"

namespace PvZ {

    Projectile* Projectile::create(Projectile::Type projectileType, Vector2f&& position) {
        switch (projectileType) {
        case Projectile::Type::PEA:
            return new Pea{ position };
        default:
            return nullptr;
        }
    }

}