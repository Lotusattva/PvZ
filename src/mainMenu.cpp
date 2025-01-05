#include "MainMenu.hpp"

namespace PvZ {
    MainMenu::MainMenu() {
        button.setPosition(buttonPos);
        buttonHighlight.setPosition(buttonPos);
    }

    GameState MainMenu::play() {
        static bool clickedStart{ false }, holdingClick{ false };

        drawSprite(background);

        while (const auto event{ window.pollEvent() }) {
            if (event->is<Event::Closed>()) {
                window.close();
                return GameState::MAIN_MENU;
            }
            if (const auto * keyPressed{ event->getIf<Event::KeyPressed>() }) {
                if (keyPressed->scancode == Keyboard::Scancode::Escape) {
                    window.close();
                    return GameState::MAIN_MENU;
                }
            }
            if (const auto * mouseButtonPressed{ event->getIf<Event::MouseButtonPressed>() }) {
                if (mouseButtonPressed->button == Mouse::Button::Left) {
                    holdingClick = true;
                    if (hoverOverRectangle({ buttonPos, buttonSize }))
                        clickedStart = true;
                }
            }
            if (const auto * mouseButtonReleased{ event->getIf<Event::MouseButtonReleased>() }) {
                if (mouseButtonReleased->button == Mouse::Button::Left) {
                    if (clickedStart && hoverOverRectangle({ buttonPos, buttonSize })) {
                        clickedStart = false;
                        return GameState::PLAY;
                    }
                    holdingClick = false;
                }
            }
        }

        if (hoverOverRectangle({ buttonPos, buttonSize })) {
            if (holdingClick && clickedStart)
                drawSprite(button);
            else
                drawSprite(buttonHighlight);
        } else
            drawSprite(button);

        return GameState::MAIN_MENU;
    }
}