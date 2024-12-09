#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include "Row.hpp"
#include "PvZ.hpp"
#include "Stage.hpp"

using namespace sf;

class Level : public Stage {
protected:
    vector<Row*>* rows;
    const short numRows;
public:
    Level( vector<Row*>* rows, short numRows) : rows(rows), numRows(numRows) { }
    virtual ~Level() = default;

    virtual GameState play(Event& event) = 0;

    static Level* makeLevel(LevelState levelState);
};

#endif // LEVEL_HPP