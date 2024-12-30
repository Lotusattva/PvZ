#ifndef PEASHOOTER_HPP
#define PEASHOOTER_HPP

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

        static inline const Textures textures;
        Frames idle{ &textures.idleTextures };
    public:
        Peashooter(short col);
        Peashooter(const Peashooter&) = delete;
        Peashooter(Peashooter&&) = delete;
        ~Peashooter() = default;

        bool action() override;
        void shoot() override;
    };
}

#endif // PEASHOOTER_HPP