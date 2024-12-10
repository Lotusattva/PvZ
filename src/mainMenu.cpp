#include "MainMenu.hpp"

namespace PvZ {
    class MainMenu::Sprites {
    private:
        Texture backgroundTexture;
        Texture buttonTexture;
        Texture buttonHighlightTexture;

    public:
        Sprite background;
        Sprite button;
        Sprite buttonHighlight;
        Vector2f buttonPos;
        Vector2f buttonSize;
        Sprites();
    };

    MainMenu::Sprites::Sprites() {
        buttonPos = { 480, 80 };
        buttonSize = { 331, 145 };

        backgroundTexture.loadFromFile("res/img/mainMenu/mainMenu.png");
        background.setTexture(backgroundTexture);

        buttonTexture.loadFromFile("res/img/mainMenu/button.png");
        button.setTexture(buttonTexture);
        button.setPosition(buttonPos);

        buttonHighlightTexture.loadFromFile("res/img/mainMenu/buttonHighlight.png");
        buttonHighlight.setTexture(buttonHighlightTexture);
        buttonHighlight.setPosition(buttonPos);
    }

    MainMenu::MainMenu() {
        sprites = new Sprites();
    }

    MainMenu::~MainMenu() {
        delete sprites;
    }

    GameState MainMenu::play(Event& event) {
        static bool clickedStart = false;
        static bool holdingClick = false;

        drawSprite(sprites->background);

        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    return GameState::MAIN_MENU;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Escape) {
                        window.close();
                        return GameState::MAIN_MENU;
                    }
                    break;
                case Event::MouseButtonPressed:
                    holdingClick = true;
                    if (hoverOverArea(sprites->buttonPos, sprites->buttonSize))
                        clickedStart = true;
                    break;
                case Event::MouseButtonReleased:
                    if (clickedStart && hoverOverArea(sprites->buttonPos, sprites->buttonSize)) {
                        clickedStart = false;
                        return GameState::PLAY;
                    }
                    holdingClick = false;
                    break;
                default:
                    break;
            }
        }

        if (hoverOverArea(sprites->buttonPos, sprites->buttonSize)) {
            if (holdingClick && clickedStart)
                drawSprite(sprites->button);
            else
                drawSprite(sprites->buttonHighlight);
        } else
            drawSprite(sprites->button);

        return GameState::MAIN_MENU;
    }
}