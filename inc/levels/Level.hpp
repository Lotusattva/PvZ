#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Row.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

class Level {
private:
    RenderWindow* window;
    const Row* rows;
    const short int numRows;
public:
    Level(RenderWindow* window, const Row* rows, short int numRows) : window(window), rows(rows), numRows(numRows) {}
    virtual ~Level() = default;
};

#endif // LEVEL_HPP