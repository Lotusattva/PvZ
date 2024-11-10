#include <iostream>
#include <SFML/Graphics.hpp>
#include "EventHandle.hpp"
#include "CustomCursor.hpp"

using namespace sf;

struct {
    Vector2u windowSize = { 900u, 600u };
    int frameRate = 120;
    bool VSync = true;
    bool customCursor = true;
} Settings;

// TODO: allow adjust settings

Texture loadTexture(const std::string& filepath) {
    Texture texture;
    if (!texture.loadFromFile(filepath)) {
        std::cerr << "Error: Unable to load texture from '" << filepath << "'" << std::endl;
    }
    return texture;
}

int main() {
    auto window = RenderWindow({ Settings.windowSize.x, Settings.windowSize.y }, "PvZ", Style::Close | Style::Titlebar);
    window.setFramerateLimit(Settings.frameRate);
    window.setVerticalSyncEnabled(Settings.VSync);
    window.setMouseCursor(getCustomCursor(Settings.customCursor));

    // Center the window
    VideoMode desktop = VideoMode::getDesktopMode();
    int posX = (desktop.width - Settings.windowSize.x) / 2;
    int posY = (desktop.height - Settings.windowSize.y) / 2;
    window.setPosition(Vector2i(posX, posY));

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
            case Event::MouseMoved:
                handleMouseMovement(event);
                break;
            default:
                break;
            }

            auto texture = loadTexture("../res/img/startmenu/menu.png");
            Sprite sprite(texture);

            window.clear(Color::Transparent);
            window.draw(sprite);
            window.display();
        }
    }
}
