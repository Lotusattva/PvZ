#include "Game.hpp"
#include <iostream>
#include "MainMenu.hpp"
#include "levels/Level.hpp"

namespace PvZ {
    Game::Game() :
        gameState{ GameState::MAIN_MENU },
        levelState{ LevelState::LEVEL1 },
        stage{ makeStage(GameState::MAIN_MENU) },
        PAUSE{ false },
        pressedEscape{ false } {
        setWindow({ 900u,600u }, 60, true, true);
    }

    void Game::run() {
        GameState nextState = gameState;
        while (window.isOpen()) {
            // always clear window and draw background
            window.clear();

            nextState = stage->play(event);

            if (gameState != nextState) {
                gameState = nextState;
                delete stage;
                stage = makeStage(gameState);
            }

            window.display();
        }
    }

    Stage* Game::makeStage(GameState gameState) {
        switch (gameState) {
            case GameState::MAIN_MENU:
                return new MainMenu;
            case GameState::PLAY:
                return makeLevel(levelState);
            default:
                return nullptr;
        }
    }
}