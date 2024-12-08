#ifndef PVZ_HPP
#define PVZ_HPP

#include <SFML/Graphics.hpp>
#include "PvZSprites.hpp"
#include "../inc/levels/Level.hpp"
#include "../inc/levels/Level1.hpp"

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
        PLAY,
        GAME_WIN,
        GAME_LOSE
    };

    enum class LevelState {
        LEVEL1
    };

    RenderWindow window;
    Event event;

    Settings settings;
    GameState gameState;
    LevelState levelState;
    Level* level;
    bool PAUSE;
    bool pressedEscape;
    MainMenuSprites* mainMenuSprites;

    Level* makeLevel();

    GameState mainMenu();
    GameState playLevel();
    GameState gameWin();
    GameState gameLose();

public:

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

    PvZ();
    void run();
};

#endif // PVZ_HPP