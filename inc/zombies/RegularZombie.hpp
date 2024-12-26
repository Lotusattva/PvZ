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

        class Textures {
        private:
            static inline const short IDLE_FRAMES{ 11 }, WALK_FRAMES{ 22 }, ATTACK_FRAMES{ 20 }, DEATH_FRAMES{ 20 };

        public:
            vector<Texture> idleTextures, walkTextures, attackTextures, deathTextures;
            Textures();
            Textures(const Textures&) = delete;
            Textures(Textures&&) = delete;
            ~Textures() = default;
        };

        static inline const Textures sprites;

        Frames idle{ &sprites.idleTextures }, walk{ &sprites.walkTextures }, attack{ &sprites.attackTextures },
            death{ &sprites.deathTextures };

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