#ifndef REGULARZOMBIE_HPP
#define REGULARZOMBIE_HPP

#include "Zombie.hpp"

namespace PvZ {

    /**
     * @brief Regular zombie class -- to be implemented
     */
    class RegularZombie : public Zombie {
    private:
        static inline const ms RegZombMvmtIntrvl{ 20ms }, RegZombAttkIntrvl{ 500ms };
        static inline const Vector2f RegZombHitbox{ 90.f,120.f }, RegZombCenter{ 110.f,75.f };

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