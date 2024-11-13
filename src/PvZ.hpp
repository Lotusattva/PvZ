#ifndef PVZ_HPP
#define PVZ_HPP

#include <SFML/Graphics.hpp>
#include "PvZSprites.hpp"

using namespace sf;

class PvZ {

private:
    struct Settings {
        Vector2u windowSize;
        int frameRate;
        bool VSync;
        bool customCursor;
    };

    enum GAME_STATE {
        MAIN_MENU,
        LEVEL1,
        GAME_WIN,
        GAME_LOSE
    };

    RenderWindow window;
    Event event;

    Settings settings;
    GAME_STATE gameState;
    bool PAUSE;
    bool pressedEscape;


    bool hoverOverArea(const Vector2f& buttonPos, const Vector2f& buttonSize);

    /**
     *@brief Draws a sprite at a given position
     *
     * @param sprite
     * @param position
     */
    void drawSprite(Sprite& sprite, const Vector2f& position);

    /**
     *@brief Draws a sprite at its current position. Default position is (0, 0)
     *
     * @param sprite
     */
    void drawSprite(Sprite& sprite);

    void loadNewSprites();

    MainMenuSprites* mainMenuSprites;
    Level1Sprites* level1Sprites;

    GAME_STATE mainMenu();
    GAME_STATE level1();
    GAME_STATE gameWin();
    GAME_STATE gameLose();

public:
    PvZ();
    void run();
};

#endif // PVZ_HPP