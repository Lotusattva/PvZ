#include "levels/cards/Card.hpp"

namespace PvZ {
    Card::Card(ushort sunCost, ms rechargeTime, const string& cardTexturePath, const string& plantTexturePath, const Vector2f& position) :
        sunCost{ sunCost }, rechargeTime{ rechargeTime }, lastUsed{ 0ms }, isReady{ true }, isDragged{ false }, position{ position } {
        cardTexture.loadFromFile(cardTexturePath);
        cardSprite.setTexture(cardTexture);
        cardSprite.setPosition(position);

        plantTexture.loadFromFile(plantTexturePath);
        plantSprite.setTexture(plantTexture);
    }

    void Card::draw() {
        drawSprite(cardSprite);
        if (isDragged) {
            auto mousePos = Mouse::getPosition(window);
            plantSprite.setPosition(mousePos.x, mousePos.y);
            drawSprite(plantSprite);
        }
    }

    void Card::click() {
        if (hoverOverArea(cardSprite.getPosition(), Vector2f(cardSprite.getGlobalBounds().width, cardSprite.getGlobalBounds().height))) {
            isDragged = true;
        }
    }

    void Card::drop() {
        if (isDragged) {
            isDragged = false;
        }
    }
}