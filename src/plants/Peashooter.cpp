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

    Peashooter::Peashooter(short row) :
        ShooterPlant{ 6, row, Projectile::Type::PEA, 8, 1000ms } {}

    Peashooter::~Peashooter() {}

    bool Peashooter::action() {
        if (!isAlive()) {
            return false;
        }
        return true;
    }

    void Peashooter::shoot() {

    }
}