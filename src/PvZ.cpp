#include "PvZ.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.hpp"
#include "levels/Level.hpp"

using namespace sf;



PvZ::PvZ() :
    gameState(GameState::MAIN_MENU),
    levelState(LevelState::LEVEL1),
    stage(makeStage(GameState::MAIN_MENU)),
    PAUSE(false),
    pressedEscape(false),
    settings({ { 900, 600 }, 60, true, true }) {
    Stage::setWindow(settings.windowSize, settings.frameRate, settings.VSync, settings.customCursor);
}

void PvZ::run() {
    GameState nextState = gameState;
    while (stage->window.isOpen()) {
        // always clear window and draw background
        stage->window.clear();
        while (stage->window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    stage->window.close();
                    return;
                default:
                    nextState = stage->play(event);
                    break;
            }
        }

        if (nextState != gameState) {
            gameState = nextState;
            delete stage;
            stage = makeStage(gameState);
        }

        stage->window.display();
    }
}

Stage* PvZ::makeStage(GameState gameState) {
    switch (gameState) {
        case GameState::MAIN_MENU:
            return new MainMenu();
        case GameState::PLAY:
            return Level::makeLevel(levelState);
        default:
            return nullptr;
    }
}