#include "../inc/PvZ.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../inc/CustomCursor.hpp"
#include "../inc/levels/Level1.hpp"

using namespace sf;

bool PvZ::hoverOverArea(const Vector2f& buttonPos, const Vector2f& buttonSize) const {
    Vector2i mousePos = Mouse::getPosition(window);
    return mousePos.x >= buttonPos.x && mousePos.x <= buttonPos.x + buttonSize.x &&
        mousePos.y >= buttonPos.y && mousePos.y <= buttonPos.y + buttonSize.y;
}

void PvZ::drawSprite(Sprite& sprite, const Vector2f& position) {
    sprite.setPosition(position);
    window.draw(sprite);
}

void PvZ::drawSprite(const Sprite& sprite) {
    window.draw(sprite);
}

PvZ::PvZ() :
    gameState(GameState::MAIN_MENU),
    levelState(LevelState::NONE),
    level(nullptr),
    PAUSE(false),
    pressedEscape(false),
    mainMenuSprites(new MainMenuSprites()),
    settings({ { 900, 600 }, 60, true, true }) {
    ////// Init window
    // Set window size
    window.create(VideoMode(settings.windowSize.x, settings.windowSize.y),
        "PvZ", Style::Close | Style::Titlebar);
    // Set frame rate
    window.setFramerateLimit(settings.frameRate);
    // Set VSync
    window.setVerticalSyncEnabled(settings.VSync);
    // Set custom cursor
    window.setMouseCursor(getCustomCursor(settings.customCursor));
    // Center the window
    VideoMode desktop = VideoMode::getDesktopMode();
    int posX = (desktop.width - settings.windowSize.x) / 2;
    int posY = (desktop.height - settings.windowSize.y) / 2;
    window.setPosition(Vector2i(posX, posY));
}

void PvZ::run() {
    while (window.isOpen()) {
        // always clear window and draw background
        window.clear();
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    return;
                case Event::LostFocus:
                    PAUSE = true;
                    break;
                case Event::GainedFocus:
                    PAUSE = false;
                    break;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Escape) {
                        pressedEscape = true;
                    }
                    break;
                default:
                    break;
            }
        }

        switch (gameState) {
            case GameState::MAIN_MENU:
                gameState = mainMenu();
                if (gameState == GameState::PLAY) {
                    level = makeLevel();
                }
                break;
            case GameState::PLAY:
                gameState = playLevel(level);
                if (gameState != GameState::PLAY) {
                    delete level;
                }
                break;
            case GameState::GAME_WIN:
                break;
            case GameState::GAME_LOSE:
                break;
        }
        window.display();
    }
}

Level* PvZ::makeLevel() {
    switch (levelState) {
        case LevelState::LEVEL1:
            return new Level1();
            break;
        default:
            return nullptr;
    }
}

PvZ::GameState PvZ::playLevel(Level* level) {

    if (pressedEscape) {
        pressedEscape = false;
        return GameState::MAIN_MENU;
    }

    // handle events
    switch (event.type) {
        case Event::LostFocus:
            PAUSE = true;
            break;
        case Event::GainedFocus:
            PAUSE = false;
            break;
        default:
            break;
    }

    return GameState::PLAY;
}