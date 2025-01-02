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
        const short numRows;
        list<Actor*> actors;
    public:
        static inline constexpr Vector2f gridOrigin{ 260.f,80.f };
        static inline constexpr float cellWidth{ 80.f }, cellHeight{ 96.f };
        Level(short numRows) : numRows(numRows) {}
        Level(const Level&) = delete;
        Level(Level&&) = delete;
        virtual ~Level() = default;

        virtual GameState play() = 0;

        list<Actor*>& getActors() { return actors; }
    };

    inline Level* currentLevel{ nullptr };

    Level* makeLevel(LevelState levelState);
}
#endif // LEVEL_HPP