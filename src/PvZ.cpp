#include <iostream>
#include <SFML/Graphics.hpp>
#include "EventHandle.hpp"
#include "CustomCursor.hpp"

using namespace sf;

class PvZ {

private:

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

    enum GameState {
        START_MENU,
        LEVEL1,
        GAME_OVER_WIN,
        GAME_OVER_LOSE
    };

    void drawScreen(RenderWindow* window) {
        if (PAUSED) {
            //draw pause screen
        }
        else {
            switch (gameState) {
            case START_MENU: {
                auto startMenuTexture = loadTexture("../res/img/startmenu/menu.png");
                Sprite startMenuSprite(startMenuTexture);
                window->draw(startMenuSprite);
                auto startButtonTexture = loadTexture("../res/img/startmenu/button.png");
                Sprite startButtonSprite(startButtonTexture);
                startButtonSprite.setPosition(470, 70);
                window->draw(startButtonSprite);
                break;
            }
            default:
                break;
            }
        }
    }

    bool PAUSED;
    GameState gameState;

public:

    PvZ() {
        PAUSED = false;
        gameState = START_MENU;
    }

    void game() {
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

                window.clear(Color::Transparent);
                drawScreen(&window);
                window.display();
            }
        }
    }
};

int main() {
    PvZ PvZgame;
    PvZgame.game();
    return 0;
}