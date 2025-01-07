#include "plants/Peashooter.hpp"

namespace PvZ {

    Peashooter::Textures::Textures() {
        string idle_path{ RES_PATH + "img/plant/pea/" }, ext{ ".png" };
        idleTextures.reserve(IDLE_FRAMES);
        for (auto i : range(1, IDLE_FRAMES + 1)) {
            Texture tex{ idle_path + to_string(i) + ext };
            idleTextures.push_back(tex);
        }
    }

    void Peashooter::shoot() {
        // TODO: implement this
        static const Vector2f spawnOffset{ 60.f, 10.f };
        auto newPea = Projectile::create(peaType, position + spawnOffset);
        currentLevel->addActor(newPea);
    }
}