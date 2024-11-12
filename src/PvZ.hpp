#ifndef PVZ_HPP
#define PVZ_HPP

#include <SFML/Graphics.hpp>
#include "Draw.hpp"

using namespace sf;

class PvZ {

private:
    struct Settings {
        Vector2u windowSize;
        int frameRate;
        bool VSync;
        bool customCursor;
    };

    enum GameState {
        MAIN_MENU,
        LEVEL1,
        GAME_OVER_WIN,
        GAME_OVER_LOSE
    };

    Settings settings;
    bool PAUSE;
    bool ESC;
    Vector2i MOUSE_CLICK_POS;
    bool HOLDING_MOUSE;
    GameState gameState;
    RenderWindow window;
    Event event;
    Mouse mouse;
    Draw draw;

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