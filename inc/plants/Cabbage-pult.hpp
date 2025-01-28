#ifndef CABBAGEPULT_HPP
#define CABBAGEPULT_HPP

#include "projectiles/Projectile.hpp"
#include "ShooterPlant.hpp"
#include <vector>

namespace PvZ {

    /**
     * @brief CabbagePult class -- to be implemented
     */
    class CabbagePult : public ShooterPlant {
    private:
        class Textures {
        private:
            static inline constexpr short IDLE_FRAMES{ 13 };

        public:
            std::vector<Texture> idleTextures;
            Textures();
            Textures(const Textures&) = delete;
            Textures(Textures&&) = delete;
            ~Textures() = default;
        };

        static constexpr inline short cabbagePultHealth{ 8 };
        static constexpr inline Projectile::Type cabbageType{ Projectile::Type::CABBAGE };
        static constexpr inline short attackRange{ 8 }; // unit: number of cells
        static constexpr inline ms attackInterval{ 1200ms };

        static inline const Textures textures;
        Frames idle{ textures.idleTextures };

    public:
        CabbagePult(short col, short row) : ShooterPlant{ cabbagePultHealth, col, row, cabbageType, attackRange, attackInterval } {}
        CabbagePult(const CabbagePult&) = delete;
        CabbagePult(CabbagePult&&) = delete;
        ~CabbagePult() = default;

        void shoot() override {
            // Implement shooting logic here
            
            Projectile cabbageProjectile{ cabbageType, getCol(), getRow() };
            
        }

        Frames& getFrames() override { return idle; }
    };

    // Define the constructor for Textures
    CabbagePult::Textures::Textures() {
        // Load image 
    }

    // Define the static member
    const CabbagePult::Textures CabbagePult::textures;

}

#endif // CABBAGEPULT_HPP