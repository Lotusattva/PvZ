#ifndef LEVEL1_HPP
#define LEVEL1_HPP

#include "Level.hpp"

namespace PvZ {

    /**
     * @brief Level 1
     */
    class Level1 : public Level {
    private:
        class Sprites;

        Sprites* sprites;
    public:

        Level1();
        ~Level1();
        GameState play(Event& event) override;
    };
}

#endif // LEVEL1_HPP