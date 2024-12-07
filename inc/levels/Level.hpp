#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Row.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

class Level {
protected:
    vector<Row*>* rows;
    const short numRows;
public:
    Level(vector<Row*>* rows, short numRows) : rows(rows), numRows(numRows) {}
    virtual ~Level() = default;
};

#endif // LEVEL_HPP