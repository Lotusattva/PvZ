#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Stage.hpp"
#include "Actor.hpp"
#include <list>

namespace PvZ {

    /**
     * @brief Abstract base class for levels
     */
    class Level : public Stage {
    protected:
        inline static const Vector2u gridOrigin = { 260u,80u };
        inline static const ushort cellWidth{ 80 };
        inline static const ushort cellHeight{ 96 };
        const ushort numRows;

        list<Actor*> actors;
    public:
        Level(ushort numRows) : numRows(numRows) {}
        virtual ~Level() = default;

        virtual GameState play(Event& event) = 0;
    };

    Level* makeLevel(LevelState levelState);
}
#endif // LEVEL_HPP