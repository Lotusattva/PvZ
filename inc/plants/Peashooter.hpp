#ifndef PEASHOOTER_HPP
#define PEASHOOTER_HPP

#include "projectiles/Projectile.hpp"
#include "ShooterPlant.hpp"

namespace PvZ {

    /**
     * @brief Peashooter class -- to be implemented
     */
    class Peashooter : public ShooterPlant {
    private:
        class Textures {
        private:
            static inline constexpr short IDLE_FRAMES{ 13 };

        public:
            vector<Texture> idleTextures;
            Textures();
            Textures(const Textures&) = delete;
            Textures(Textures&&) = delete;
            ~Textures() = default;
        };

        static constexpr inline short peashooterHealth{ 6 };
        static constexpr inline Projectile::Type peaType{ Projectile::Type::PEA };
        static constexpr inline short attackRange{ 8 }; // unit: number of cells
        static constexpr inline ms attackInterval{ 1000ms };

        static inline const Textures textures;
        Frames idle{ textures.idleTextures };

    public:
        Peashooter(short col, short row) : ShooterPlant{ peashooterHealth, col, row, peaType, attackRange, attackInterval } {}
        Peashooter(const Peashooter&) = delete;
        Peashooter(Peashooter&&) = delete;
        ~Peashooter() = default;

        void shoot() override;
        Frames& getFrames() override { return idle; }
    };
}

#endif // PEASHOOTER_HPP