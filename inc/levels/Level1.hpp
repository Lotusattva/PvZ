#ifndef LEVEL1_HPP
#define LEVEL1_HPP

#include "Level.hpp"

class Level1Sprites {
private:
    Texture backgroundTexture;
    Texture topbarTexture;
public:
    Sprite background;
    Sprite topbar;

    Vector2f topbarPos;
    Vector2f topbarSize;

    Level1Sprites();
};

class Level1 : public Level {
private:

    static vector<Row*>* makeRows();
    static Row* makeRow1();
    static Row* makeRow2();
    static Row* makeRow3();

    Level1Sprites* sprites;
public:

    Level1(RenderWindow* window) : sprites(new Level1Sprites()), Level(window, makeRows(), 3) { }
    ~Level1();
    void action() override;
};

#endif // LEVEL1_HPP