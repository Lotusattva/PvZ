#ifndef CARD_HPP
#define CARD_HPP

#include "Util.hpp"

namespace{
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

            void draw();
            void click();
            void drop();
    };
}

#endif // CARD_HPP