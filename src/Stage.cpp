#include "Stage.hpp"
#include <iostream>

void Stage::setWindow(Vector2u windowSize, short int frameRate, bool VSync, bool customCursor) {
    ////// Init window
    // Set window size
    window.create(VideoMode(windowSize.x, windowSize.y),
        "PvZ", Style::Close | Style::Titlebar);
    // Set frame rate
    window.setFramerateLimit(frameRate);
    // Set VSync
    window.setVerticalSyncEnabled(VSync);
    // Set custom cursor
    window.setMouseCursor(getCustomCursor(customCursor));
    // Center the window
    VideoMode desktop = VideoMode::getDesktopMode();
    int posX = (desktop.width - windowSize.x) / 2;
    int posY = (desktop.height - windowSize.y) / 2;
    window.setPosition(Vector2i(posX, posY));
}


Cursor& Stage::getCustomCursor(bool useCustomCursor) {
    if (!useCustomCursor) {
        static Cursor defaultCursor;
        defaultCursor.loadFromSystem(Cursor::Arrow);
        return defaultCursor;
    }
    Image cursorImage;
    if (!cursorImage.loadFromFile("res/img/cursor/spike.png")) {
        std::cerr << "Error: Unable to load cursor image from 'res/img/cursor/spike.png'" << std::endl;
        static Cursor defaultCursor;
        defaultCursor.loadFromSystem(Cursor::Arrow);
        return defaultCursor;
    }
    Vector2u cursorSize = cursorImage.getSize();
    Vector2u cursorHotspot = { 0u, 0u };

    static Cursor customCursor;
    customCursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorSize, cursorHotspot);

    return customCursor;
}

bool Stage::hoverOverArea(const Vector2f& buttonPos, const Vector2f& buttonSize) {
    Vector2i mousePos = Mouse::getPosition(window);
    return mousePos.x >= buttonPos.x && mousePos.x <= buttonPos.x + buttonSize.x &&
        mousePos.y >= buttonPos.y && mousePos.y <= buttonPos.y + buttonSize.y;
}

void Stage::drawSprite(Sprite& sprite, const Vector2f& position) {
    sprite.setPosition(position);
    window.draw(sprite);
}

void Stage::drawSprite(const Sprite& sprite) {
    window.draw(sprite);
}