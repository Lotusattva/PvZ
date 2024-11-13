#include "PvZ.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "CustomCursor.hpp"

using namespace sf;

bool PvZ::hoverOverArea(const Vector2f& buttonPos, const Vector2f& buttonSize) {
    Vector2i mousePos = Mouse::getPosition(window);
    return mousePos.x >= buttonPos.x && mousePos.x <= buttonPos.x + buttonSize.x &&
        mousePos.y >= buttonPos.y && mousePos.y <= buttonPos.y + buttonSize.y;
}

void PvZ::drawSprite(Sprite& sprite, const Vector2f& position) {
    sprite.setPosition(position);
    window.draw(sprite);
}

void PvZ::drawSprite(Sprite& sprite) {
    window.draw(sprite);
}

void PvZ::loadNewSprites() {
    switch (gameState) {
    case MAIN_MENU:
        mainMenuSprites = new MainMenuSprites();
        break;
    case LEVEL1:
        level1Sprites = new Level1Sprites();
        break;
    }
}

PvZ::PvZ() :
    gameState(MAIN_MENU),
    PAUSE(false),
    pressedEscape(false),
    mainMenuSprites(new MainMenuSprites()),
    level1Sprites(nullptr),
    settings({ { 900, 600 }, 60, true, true })
{
    ////// Init window
    // Set window size
    window.create(VideoMode(settings.windowSize.x, settings.windowSize.y), "PvZ", Style::Close | Style::Titlebar);
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
        case MAIN_MENU:
            gameState = mainMenu();
            if (gameState != MAIN_MENU) {
                delete mainMenuSprites;
                mainMenuSprites = nullptr;
                loadNewSprites();
            }
            break;
        case LEVEL1:
            gameState = level1();
            if (gameState != LEVEL1) {
                delete level1Sprites;
                level1Sprites = nullptr;
                loadNewSprites();
            }
            break;
        }
        window.display();
    }
}
