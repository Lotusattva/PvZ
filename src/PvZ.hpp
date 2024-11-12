#ifndef PVZ_HPP
#define PVZ_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class PvZ {

private:
    struct Settings;

    enum GameState;

    bool PAUSE;
    bool ESC;
    Vector2i leftClickPos;
    bool holdingLeftClick;
    GameState gameState;
    RenderWindow window;
    Event event;
    Mouse mouse;

    void drawFromFile(const char* path, Vector2f position = { 0, 0 });

    void drawScreen();

    void drawMainMenu();

    void drawLevel1();

    void drawGameOverWin();

    void drawGameOverLose();

public:
    PvZ();
    void run();
};

#endif // PVZ_HPP