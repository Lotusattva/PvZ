#ifndef PVZ_HPP
#define PVZ_HPP

#include <SFML/Graphics.hpp>
#include "PvZSprites.hpp"
#include "levels/Level.hpp"

using namespace sf;

class PvZ {

private:
    struct Settings {
        Vector2u windowSize;
        short int frameRate;
        bool VSync;
        bool customCursor;
    };

    enum class GameState {
        MAIN_MENU,
        LEVEL1,
        GAME_WIN,
        GAME_LOSE
    };

    RenderWindow window;
    Event event;

    Settings settings;
    GameState gameState;
    bool PAUSE;
    bool pressedEscape;


    bool hoverOverArea(const Vector2f& buttonPos, const Vector2f& buttonSize) const;

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
    void drawSprite(const Sprite& sprite);

    void loadNewSprites();

    MainMenuSprites* mainMenuSprites;
    Level1Sprites* level1Sprites;

    GameState mainMenu();
    GameState level1();
    GameState gameWin();
    GameState gameLose();

public:
    PvZ();
    void run();

    friend class Level;
};

#endif // PVZ_HPP