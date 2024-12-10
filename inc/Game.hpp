#ifndef GAME_HPP
#define GAME_HPP

#include "Stage.hpp"

namespace PvZ {

    class Game {

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

        Game();
        void run();
    };

}

#endif // GAME_HPP