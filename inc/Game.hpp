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

        GameState gameState{ GameState::MAIN_MENU };
        LevelState levelState{ LevelState::LEVEL1 };
        Stage* stage{ makeStage(GameState::MAIN_MENU) };
        bool PAUSE{ false };
        bool pressedEscape{ false };

        /**
         * @brief Makes a new stage when game state is changed
         */
        Stage* makeStage(GameState gameState);

    public:
        Game();
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
        ~Game() = default;

        /**
         * @brief Main game loop
         */
        void run();
    };

}

#endif // GAME_HPP