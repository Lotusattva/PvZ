#include "PvZ.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "EventHandle.hpp"
#include "CustomCursor.hpp"

using namespace sf;

Texture PvZ::loadTexture(const std::string& path) {
    Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cerr << "Error loading texture from file: " << path << std::endl;
    }
    return texture;
}

void PvZ::drawScreen(RenderWindow* window) {
    if (PAUSED) {
        //draw pause screen
    }
    else {
        switch (gameState) {
        case MAIN_MENU:
            drawMainMenu(window);
            break;
        case LEVEL1:
            drawLevel1(window);
            break;
        case GAME_OVER_WIN:
            drawGameOverWin(window);
            break;
        case GAME_OVER_LOSE:
            drawGameOverLose(window);
            break;
        default:
            break;
        }
    }
}

void PvZ::drawMainMenu(RenderWindow* window) {
    // draw main menu background
    auto mainMenuBackgroundTexture = loadTexture("../res/img/mainMenu/mainMenu.png");
    Sprite mainMenuBackgroundSprite(mainMenuBackgroundTexture);
    window->draw(mainMenuBackgroundSprite);

    // draw start button
    Mouse mouse;
    auto mousePos = mouse.getPosition(*window);
    Vector2f startButtonPos = { 470, 70 };
    Vector2f buttonSize = { 331, 145 };
    Texture startButtonTexture = Texture();
    if (mousePos.x >= startButtonPos.x && mousePos.x <= startButtonPos.x + buttonSize.x &&
        mousePos.y >= startButtonPos.y && mousePos.y <= startButtonPos.y + buttonSize.y) {
        // if mouse is hovering over the start button
        startButtonTexture = loadTexture("../res/img/mainMenu/buttonHighlight.png");
    }
    else {
        startButtonTexture = loadTexture("../res/img/mainMenu/button.png");
    }
    Sprite startButtonSprite(startButtonTexture);
    startButtonSprite.setPosition(startButtonPos);
    window->draw(startButtonSprite);
}

void PvZ::drawLevel1(RenderWindow* window) {
    // TODO: draw level 1
}

void PvZ::drawGameOverWin(RenderWindow* window) {
    // TODO: draw game over win screen
}

void PvZ::drawGameOverLose(RenderWindow* window) {
    // TODO: draw game over lose screen
}

PvZ::PvZ() {
    settings.customCursor = true;
    settings.VSync = true;
    settings.frameRate = 60;
    settings.windowSize = { 900, 600 };
    PAUSED = false;
    gameState = MAIN_MENU;

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
        for (auto event = Event(); window.pollEvent(event);) {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            case Event::LostFocus:
                gamePause();
                break;
            case Event::GainedFocus:
                gameResume();
                break;
            case Event::KeyPressed:
                handleKeyPress(event);
                break;
            case Event::MouseButtonPressed:
                handleMouseClick(event);
                break;
            case Event::MouseButtonReleased:
                handleMouseRelease(event);
                break;
            default:
                break;
            }

            window.clear(Color::Transparent);
            drawScreen(&window);
            window.display();
        }
    }
}

