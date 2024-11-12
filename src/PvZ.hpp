#ifndef PVZ_HPP
#define PVZ_HPP

#include <SFML/Graphics.hpp>

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
    bool PAUSED;
    GameState gameState;
    RenderWindow window;

    Texture loadTexture(const std::string& path);

    void drawScreen(RenderWindow* window);

    void drawMainMenu(RenderWindow* window);

    void drawLevel1(RenderWindow* window);

    void drawGameOverWin(RenderWindow* window);

    void drawGameOverLose(RenderWindow* window);

public:
    PvZ();
    void run();
};

#endif // PVZ_HPP