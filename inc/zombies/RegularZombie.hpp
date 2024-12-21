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
        static inline const short IDLE_FRAMES{ 11 }, WALK_FRAMES{ 22 }, ATTACK_FRAMES{ 20 }, DEATH_FRAMES{ 20 };
        class Textures {
        public:
            Texture idle[IDLE_FRAMES], walk[WALK_FRAMES], attack[ATTACK_FRAMES], death[DEATH_FRAMES];
            Textures();
        };

        static inline const Textures textures;

        Frames idleFrames{ IDLE_FRAMES, textures.idle }, walkFrames{ WALK_FRAMES, textures.walk },
            attackFrames{ ATTACK_FRAMES, textures.attack }, deathFrames{ DEATH_FRAMES, textures.death };

    public:
        RegularZombie(ms spawnTime);
        RegularZombie(const RegularZombie&) = delete;
        RegularZombie(RegularZombie&&) = delete;
        ~RegularZombie() = default;

        bool action() override;
        void move() override;
        void attack() override;
    };
}

#endif // REGULARZOMBIE_HPP