#ifndef LEVEL1_HPP
#define LEVEL1_HPP

#include "Level.hpp"

namespace PvZ {

    /**
     * @brief Level 1
     */
    class Level1 : public Level {
    private:

        const Texture backgroundTexture{ "res/img/level/frontyard_3row.jpg" },
            topbarTexture{ "res/img/topbar/bar4.png" };
        Sprite background{ backgroundTexture }, topbar{ topbarTexture };
        const Vector2f topbarPos{ 280.f, 0.f }, topbarSize{ 522.f, 87.f };

    public:

        Level1();
        Level1(const Level1&) = delete;
        Level1(Level1&&) = delete;
        ~Level1();
        GameState play() override;
    };
}

#endif // LEVEL1_HPP