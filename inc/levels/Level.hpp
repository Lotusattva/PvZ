#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Stage.hpp"
#include "Actor.hpp"

namespace PvZ {

    /**
     * @brief Abstract base class for levels
     */
    class Level : public Stage {
    protected:
        inline static Vector2u gridOrigin = { 260,80 };
        inline static short cellWidth = 80;
        inline static short cellHeight = 96;
        short numRows;
        vector<Actor*> actors;
    public:
        Level(short numRows) : numRows(numRows) { }
        virtual ~Level() = default;

        virtual GameState play(Event& event) = 0;

        static Level* makeLevel(LevelState levelState);
    };
}
#endif // LEVEL_HPP