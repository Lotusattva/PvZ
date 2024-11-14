#include "../inc/PvZSprites.hpp"

MainMenuSprites::MainMenuSprites() {
    buttonPos = { 480, 80 };
    buttonSize = { 331, 145 };

    backgroundTexture.loadFromFile("../res/img/mainMenu/mainMenu.png");
    background.setTexture(backgroundTexture);

    buttonTexture.loadFromFile("../res/img/mainMenu/button.png");
    button.setTexture(buttonTexture);
    button.setPosition(buttonPos);

    buttonHighlightTexture.loadFromFile("../res/img/mainMenu/buttonHighlight.png");
    buttonHighlight.setTexture(buttonHighlightTexture);
    buttonHighlight.setPosition(buttonPos);
}

Level1Sprites::Level1Sprites() {
    topbarPos = { 280, 0 };
    topbarSize = { 522, 87 };

    backgroundTexture.loadFromFile("../res/img/level/frontyard_3row.jpg");
    background.setTexture(backgroundTexture);

    topbarTexture.loadFromFile("../res/img/topbar/bar4.png");
    topbar.setTexture(topbarTexture);
    topbar.setPosition(topbarPos);
}
