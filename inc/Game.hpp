#ifndef GAME_HPP
#define GAME_HPP

#include "Stage.hpp"

namespace PvZ {

    /**
     * @brief Main game class
     */
    class Game {

    private:

        Event event;

        GameState gameState;
        LevelState levelState;
        Stage* stage;
        bool PAUSE;
        bool pressedEscape;

        /**
         * @brief Makes a new stage when game state is changed
         */
        Stage* makeStage(GameState gameState);


    public:

        Game();
        void run();
    };

}

#endif // GAME_HPP