#ifndef LEVEL1_HPP
#define LEVEL1_HPP

#include "Level.hpp"

namespace PvZ {

    /**
     * @brief Level 1
     */
    class Level1 : public Level {
    private:
        class Sprites {
        private:
            Texture backgroundTexture, topbarTexture;
        public:
            Sprite background, topbar;
            static inline const Vector2f topbarPos{ 280.f, 0.f }, topbarSize{ 522.f, 87.f };

            Sprites();
            Sprites(const Sprites&) = delete;
            Sprites(Sprites&&) = delete;
            ~Sprites() = default;
        };

        Sprites* const sprites{ new Sprites };
    public:

        Level1();
        Level1(const Level1&) = delete;
        Level1(Level1&&) = delete;
        ~Level1();
        GameState play(Event& event) override;
    };
}

#endif // LEVEL1_HPP