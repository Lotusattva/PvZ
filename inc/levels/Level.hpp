#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include "Row.hpp"

using namespace sf;

class Level {
protected:
    vector<Row*>* rows;
    const short numRows;
    RenderWindow* window;
public:
    Level(RenderWindow* window, vector<Row*>* rows, short numRows) : window(window), rows(rows), numRows(numRows) { }
    virtual ~Level() = default;

    virtual void action() = 0;
};

#endif // LEVEL_HPP