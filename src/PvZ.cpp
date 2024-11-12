#include "PvZ.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "CustomCursor.hpp"

using namespace sf;

struct PvZ::Settings {
    Vector2u windowSize;
    int frameRate;
    bool VSync;
    bool customCursor;
};

struct PvZ::MainMenuSprites {
    Sprite background;
    Sprite button;
    Sprite buttonHighlight;
    Texture backgroundTexture;
    Texture buttonTexture;
    Texture buttonHighlightTexture;
};

struct PvZ::spriteDimensions {
    Vector2f buttonPos;
    Vector2f buttonSize;
};

bool PvZ::overButton(Vector2f* buttonPos, Vector2f* buttonSize) {
    Vector2i mousePos = Mouse::getPosition(window);
    return mousePos.x >= buttonPos->x && mousePos.x <= buttonPos->x + buttonSize->x &&
        mousePos.y >= buttonPos->y && mousePos.y <= buttonPos->y + buttonSize->y;
}

void PvZ::drawSprite(Sprite* sprite, Vector2f position) {
    sprite->setPosition(position);
    window.draw(*sprite);
}

void PvZ::drawSprite(Sprite* sprite) {
    window.draw(*sprite);
}

PvZ::PvZ() {
    PAUSE = false;

    ////// Init settings
    settings = new Settings();
    settings->customCursor = true;
    settings->VSync = true;
    settings->frameRate = 60;
    settings->windowSize = { 900, 600 };

    ////// Init window
    // Set window size
    window.create(VideoMode(settings->windowSize.x, settings->windowSize.y), "PvZ", Style::Close | Style::Titlebar);
    // Set frame rate
    window.setFramerateLimit(settings->frameRate);
    // Set VSync
    window.setVerticalSyncEnabled(settings->VSync);
    // Set custom cursor
    window.setMouseCursor(getCustomCursor(settings->customCursor));
    // Center the window
    VideoMode desktop = VideoMode::getDesktopMode();
    int posX = (desktop.width - settings->windowSize.x) / 2;
    int posY = (desktop.height - settings->windowSize.y) / 2;
    window.setPosition(Vector2i(posX, posY));

    ////// load main menu sprites
    sprites = new MainMenuSprites();
    // load background sprite
    sprites->backgroundTexture.loadFromFile("../res/img/mainMenu/mainMenu.png");
    sprites->background.setTexture(sprites->backgroundTexture);
    // load button sprite
    sprites->buttonTexture.loadFromFile("../res/img/mainMenu/button.png");
    sprites->button.setTexture(sprites->buttonTexture);
    sprites->button.setPosition(470, 70);
    // load highlighted button sprite
    sprites->buttonHighlightTexture.loadFromFile("../res/img/mainMenu/buttonHighlight.png");
    sprites->buttonHighlight.setTexture(sprites->buttonHighlightTexture);
    sprites->buttonHighlight.setPosition(470, 70);

    ////// set main menu sprite dimensions
    dimensions = new spriteDimensions();
    dimensions->buttonPos = { 470, 70 };
    dimensions->buttonSize = { 331, 145 };
}

void PvZ::run() {
    bool clickedStart = false;
    bool holdingClick = false;
    while (window.isOpen()) {
        // always clear window and draw background
        window.clear();
        window.draw(sprites->background);

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                delete sprites;
                delete settings;
                delete dimensions;
                return;
            }

            // handle events
            switch (event.type) {
            case Event::LostFocus:
                PAUSE = true;
                break;
            case Event::GainedFocus:
                PAUSE = false;
                break;
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape) {
                    // ask if user wants to quit
                    // if yes:
                    window.close();
                    delete sprites;
                    delete settings;
                    delete dimensions;
                    return;
                    // else continue
                }
            case Event::MouseButtonPressed:
                holdingClick = true;
                if (overButton(&dimensions->buttonPos, &dimensions->buttonSize))
                    clickedStart = true;
                break;
            case Event::MouseButtonReleased:
                if (clickedStart && overButton(&dimensions->buttonPos, &dimensions->buttonSize)) {
                    // delete sprites;
                    // delete settings;
                    // delete dimensions;
                    // start game
                }
                holdingClick = false;
                break;
            default:
                break;
            }
        }

        if (overButton(&dimensions->buttonPos, &dimensions->buttonSize)) {
            if (holdingClick && clickedStart)
                drawSprite(&sprites->button);
            else
                drawSprite(&sprites->buttonHighlight);
        }
        else
            drawSprite(&sprites->button);

        window.display();
    }
}

