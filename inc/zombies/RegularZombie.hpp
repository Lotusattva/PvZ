#ifndef REGULARZOMBIE_HPP
#define REGULARZOMBIE_HPP

#include "Zombie.hpp"

namespace PvZ {

    /**
     * @brief Regular zombie class -- to be implemented
     */
    class RegularZombie : public Zombie {
    private:
        static constexpr inline ms RegZombMovementInterval{ 20ms }, RegZombAttackInterval{ 500ms };
        static constexpr inline Vector2f hitboxSize{ 90.f,120.f }, centerOffset{ 110.f,75.f };

        class Textures {
        private:
            static constexpr inline short IDLE_FRAMES{ 11 }, WALK_FRAMES{ 22 }, ATTACK_FRAMES{ 20 }, DEATH_FRAMES{ 20 };

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

        static constexpr inline auto isAlivePlant = [](Actor* actor) { return actor->getType() == Actor::Type::PLANT && actor->isAlive(); };
    public:
        RegularZombie(ms spawnTime, int row);
        RegularZombie(const RegularZombie&) = delete;
        RegularZombie(RegularZombie&&) = delete;
        ~RegularZombie() = default;

        bool action() override;
        const Rectangle getHitbox() const override { return { position, hitboxSize }; }
        const Vector2f getCenter() const override { return position + centerOffset; }
    };
}

#endif // REGULARZOMBIE_HPP