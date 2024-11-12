#include "PvZ.hpp"

bool overButton(Vector2i mousePos) {
    Vector2f buttonPos = { 470, 70 };
    Vector2f buttonSize = { 331, 145 };
    return mousePos.x >= buttonPos.x && mousePos.x <= buttonPos.x + buttonSize.x &&
        mousePos.y >= buttonPos.y && mousePos.y <= buttonPos.y + buttonSize.y;
}

void PvZ::drawMainMenu() {
    // draw main menu background
    draw.drawFromFile("../res/img/mainMenu/mainMenu.png");

    // draw start button
    auto mousePos = mouse.getPosition(window);
    if (HOLDING_MOUSE) {
        if (overButton(MOUSE_CLICK_POS)) {
            draw.drawFromFile("../res/img/mainMenu/button.png", { 470, 70 });
        }
        else {
            draw.drawFromFile("../res/img/mainMenu/buttonHighlight.png", { 470, 70 });
        }
    }
    else {
        if (overButton(mousePos)) {
            draw.drawFromFile("../res/img/mainMenu/buttonHighlight.png", { 470, 70 });
        }
        else {
            draw.drawFromFile("../res/img/mainMenu/button.png", { 470, 70 });
        }
    }
}