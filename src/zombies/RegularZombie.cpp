#include <zombies/RegularZombie.hpp>

namespace PvZ {
    RegularZombie::RegularZombie(ms spawnTime) : Zombie{ 10, 100ms, 100ms, spawnTime } {}

    bool RegularZombie::action() {
        return true;
    }

    void move() {
        return;
    }

    void attack() {
        return;
    }

}