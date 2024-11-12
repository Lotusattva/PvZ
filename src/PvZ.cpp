#include "PvZ.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "CustomCursor.hpp"

using namespace sf;

void PvZ::drawScreen() {
        switch (gameState) {
        case MAIN_MENU:
            drawMainMenu();
            break;
        case LEVEL1:
            drawLevel1();
            break;
        case GAME_OVER_WIN:
            drawGameOverWin();
            break;
        case GAME_OVER_LOSE:
            drawGameOverLose();
            break;
        default:
            break;
        }
}

void PvZ::drawLevel1() {
    // TODO: draw level 1
}

void PvZ::drawGameOverWin() {
    // TODO: draw game over win screen
}

void PvZ::drawGameOverLose() {
    // TODO: draw game over lose screen
}

PvZ::PvZ() {
    settings.customCursor = true;
    settings.VSync = true;
    settings.frameRate = 60;
    settings.windowSize = { 900, 600 };
    PAUSE = false;
    ESC = false;
    MOUSE_CLICK_POS = { -1, -1 };
    HOLDING_MOUSE = false;
    gameState = MAIN_MENU;
    event = Event();
    draw = Draw(&window);

    window.create(VideoMode(settings.windowSize.x, settings.windowSize.y), "PvZ", Style::Close | Style::Titlebar);
    window.setFramerateLimit(settings.frameRate);
    window.setVerticalSyncEnabled(settings.VSync);
    window.setMouseCursor(getCustomCursor(settings.customCursor));

    // Center the window
    VideoMode desktop = VideoMode::getDesktopMode();
    int posX = (desktop.width - settings.windowSize.x) / 2;
    int posY = (desktop.height - settings.windowSize.y) / 2;
    window.setPosition(Vector2i(posX, posY));
}

void PvZ::run() {
    // Main loop
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            case Event::LostFocus:
                PAUSE = true;
                break;
            case Event::GainedFocus:
                PAUSE = false;
                break;
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape) {
                    ESC = !ESC;
                }
                break;
            case Event::MouseButtonPressed:
                MOUSE_CLICK_POS = Mouse::getPosition(window);
                HOLDING_MOUSE = true;
                break;
            case Event::MouseButtonReleased:
                MOUSE_CLICK_POS = { -1, -1 };
                HOLDING_MOUSE = false;
                break;
            default:
                break;
            }

            window.clear(Color::Transparent);
            drawScreen();
            window.display();
        }
    }
}

