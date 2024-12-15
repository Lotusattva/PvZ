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
        inline static const Vector2u gridOrigin = { 260u,80u };
        inline static const ushort cellWidth = 80;
        inline static const ushort cellHeight = 96;
        const ushort numRows;

        /*
        When constructing a level, zombies should be added to the actors vector.
        While playing the level, plants should be added to the actors vector as well when they are planted.
        When a plant dies/is removed, or when a zombie dies, they should be deleted and replaced with a NullActor.
        DO NOT REPLACE DEAD ACTORS WITH nullptr !!!
        */

        vector<Actor*> actors;
    public:
        Level(ushort numRows) : numRows(numRows) { }
        virtual ~Level() = default;

        virtual GameState play(Event& event) = 0;
    };

    Level* makeLevel(LevelState levelState);
}
#endif // LEVEL_HPP