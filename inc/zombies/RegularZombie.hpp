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

        class Sprites {
        private:
            static inline const short IDLE_FRAMES{ 11 }, WALK_FRAMES{ 22 }, ATTACK_FRAMES{ 20 }, DEATH_FRAMES{ 20 };
            vector<Texture> idleTextures, walkTextures, attackTextures, deathTextures;
        public:
            vector<Sprite> idleSprites, walkSprites, attackSprites, deathSprites;
            Sprites();
            Sprites(const Sprites&) = delete;
            Sprites(Sprites&&) = delete;
            ~Sprites() = default;
        };

        static inline const Sprites sprites;

        Frames idle{ &sprites.idleSprites }, walk{ &sprites.walkSprites }, attack{ &sprites.attackSprites },
            death{ &sprites.deathSprites };

        // the attack animation is funky

    public:
        RegularZombie(ms spawnTime, int col);
        RegularZombie(const RegularZombie&) = delete;
        RegularZombie(RegularZombie&&) = delete;
        ~RegularZombie() = default;

        bool action() override;
    };
}

#endif // REGULARZOMBIE_HPP