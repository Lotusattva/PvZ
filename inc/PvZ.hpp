#ifndef PVZ_HPP
#define PVZ_HPP

#include <SFML/Graphics.hpp>
#include "Stage.hpp"

using namespace sf;

enum class GameState {
    MAIN_MENU,
    PLAY,
    GAME_WIN,
    GAME_LOSE
};

enum class LevelState {
    LEVEL1
};

class PvZ {

private:
    struct Settings {
        Vector2u windowSize;
        short int frameRate;
        bool VSync;
        bool customCursor;
    };

    Event event;

    Settings settings;
    GameState gameState;
    LevelState levelState;
    Stage* stage;
    bool PAUSE;
    bool pressedEscape;

    Stage* makeStage(GameState gameState);


public:

    PvZ();
    void run();
};

#endif // PVZ_HPP