#include "../inc/PvZ.hpp"

PvZ::GameState PvZ::mainMenu() {
    if (pressedEscape) {
        window.close();
    }

    static bool clickedStart = false;
    static bool holdingClick = false;

    window.draw(mainMenuSprites->background);
    // handle events
    switch (event.type) {
    case Event::MouseButtonPressed:
        holdingClick = true;
        if (hoverOverArea(mainMenuSprites->buttonPos, mainMenuSprites->buttonSize))
            clickedStart = true;
        break;
    case Event::MouseButtonReleased:
        if (clickedStart && hoverOverArea(mainMenuSprites->buttonPos, mainMenuSprites->buttonSize)) {
            clickedStart = false;
            return GameState::LEVEL1;
        }
        holdingClick = false;
        break;
    default:
        break;
    }

    if (hoverOverArea(mainMenuSprites->buttonPos, mainMenuSprites->buttonSize)) {
        if (holdingClick && clickedStart)
            drawSprite(mainMenuSprites->button);
        else
            drawSprite(mainMenuSprites->buttonHighlight);
    }
    else
        drawSprite(mainMenuSprites->button);

    return GameState::MAIN_MENU;
}