#include "../inc/PvZ.hpp"

PvZ::GameState PvZ::level1() {

    if (pressedEscape) {
        pressedEscape = false;
        return GameState::MAIN_MENU;
    }

    window.draw(level1Sprites->background);
    window.draw(level1Sprites->topbar);

    // handle events
    switch (event.type) {
    case Event::LostFocus:
        PAUSE = true;
        break;
    case Event::GainedFocus:
        PAUSE = false;
        break;
    default:
        break;
    }

    return GameState::LEVEL1;
}