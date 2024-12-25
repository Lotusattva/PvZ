#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Stage.hpp"
#include "Actor.hpp"
#include <list>

namespace PvZ {

    inline Level* level;

    /**
     * @brief Abstract base class for levels
     */
    class Level : public Stage {
    protected:
        static inline const Vector2u gridOrigin{ 260u,80u };
        static inline const short cellWidth{ 80 }, cellHeight{ 96 };

        const short numRows;
        list<Actor*> actors;
    public:
        Level(short numRows) : numRows(numRows) {}
        Level(const Level&) = delete;
        Level(Level&&) = delete;
        virtual ~Level() = default;

        virtual GameState play() = 0;

        list<Actor*>& getActors() { return actors; }
    };

    Level* makeLevel(LevelState levelState);
}
#endif // LEVEL_HPP