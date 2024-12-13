#ifndef CARD_HPP
#define CARD_HPP

#include "Util.hpp"

namespace {
    /**
     * @brief Base class for plant cards
     */
    class Card {
    protected:
        short sunCost;
        ms rechargeTime;
        ms lastUsed;
        bool isReady;
        bool isDragged;

        Texture cardTexture;
        Sprite cardSprite;

        Texture plantTexture;
        Sprite plantSprite;

        Vector2f position;

    public:
        Card(short sunCost, ms rechargeTime, const string& cardTexturePath, const string& plantTexturePath, const Vector2f& position);

        ~Card() = default;

        /**
         * @brief Draws the card (and the plant when user is dragging the card)
         */
        void draw();

        /**
         * @brief Do something when user clicks on the card
         */
        void click();

        /**
         * @brief Do something when user is no longer clicking on the card
         */
        void drop();
    };
}

#endif // CARD_HPP