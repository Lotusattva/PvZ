#ifndef LEVEL1_HPP
#define LEVEL1_HPP

#include "Level.hpp"

class Level1Sprites {
public:
    Sprite background;
    Texture backgroundTexture;

    Sprite topbar;
    Texture topbarTexture;
    Vector2f topbarPos;
    Vector2f topbarSize;

    Level1Sprites();
};



class Level1 : public Level {
private:
    Level1Sprites* sprites;

    static vector<Row*>* makeRows();
    static Row* makeRow1();
    static Row* makeRow2();
    static Row* makeRow3();
public:
    Level1();
    ~Level1();
};

#endif // LEVEL1_HPP