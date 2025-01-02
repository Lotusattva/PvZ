#ifndef REGULARZOMBIE_HPP
#define REGULARZOMBIE_HPP

#include "Zombie.hpp"

namespace PvZ {

    /**
     * @brief Regular zombie class -- to be implemented
     */
    class RegularZombie : public Zombie {
    private:
        static inline constexpr ms movementInterval{ 20ms }, attackInterval{ 500ms };
        static inline constexpr Vector2f hitbox{ 90.f,120.f }, center{ 110.f,75.f };

        class Textures {
        private:
            static inline constexpr short IDLE_FRAMES{ 11 }, WALK_FRAMES{ 22 }, ATTACK_FRAMES{ 20 }, DEATH_FRAMES{ 20 };

        public:
            vector<Texture> idleTextures, walkTextures, attackTextures, deathTextures;
            Textures();
            Textures(const Textures&) = delete;
            Textures(Textures&&) = delete;
            ~Textures() = default;
        };

        static inline const Textures textures;

        Frames idle{ &textures.idleTextures }, walk{ &textures.walkTextures }, attack{ &textures.attackTextures },
            death{ &textures.deathTextures };

        constexpr static inline auto isAlivePlant = [](const Actor* actor) { return actor->getType() == Actor::Type::PLANT && actor->isAlive(); };
    public:
        RegularZombie(ms spawnTime, int row);
        RegularZombie(const RegularZombie&) = delete;
        RegularZombie(RegularZombie&&) = delete;
        ~RegularZombie() = default;

        bool action() override;
    };
}

#endif // REGULARZOMBIE_HPP