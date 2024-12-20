#ifndef REGULARZOMBIE_HPP
#define REGULARZOMBIE_HPP

#include "Zombie.hpp"
#include <vector>

namespace PvZ {

    /**
     * @brief Regular zombie class -- to be implemented
     */
    class RegularZombie : public Zombie {
    private:
        static const short IDLE_FRAMES{ 11 };
        static const short WALK_FRAMES{ 22 };
        static const short ATTACK_FRAMES{ 21 };
        static const short DEATH_FRAMES{ 20 };
        class Sprites {
            public:
            Texture idle[IDLE_FRAMES], walk[WALK_FRAMES], attack[ATTACK_FRAMES], death[DEATH_FRAMES];
            Sprites();
        };

        static const Sprites sprites;

        Frames idleFrames{ IDLE_FRAMES, sprites.idle }, walkFrames{ WALK_FRAMES, sprites.walk },
            attackFrames{ ATTACK_FRAMES, sprites.attack }, deathFrames{ DEATH_FRAMES, sprites.death };

    public:
        RegularZombie(ms spawnTime);
        ~RegularZombie() = default;
        bool action() override;
        void move() override;
        void attack() override;
    };
}

#endif // REGULARZOMBIE_HPP