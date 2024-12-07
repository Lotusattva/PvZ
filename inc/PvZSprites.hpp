#ifndef PVZSPRITES_HPP
#define PVZSPRITES_HPP
#include <SFML/Graphics.hpp>

using namespace sf;

class MainMenuSprites {
public:
    Texture backgroundTexture;
    Sprite background;

    Sprite button;
    Texture buttonTexture;

    Sprite buttonHighlight;
    Texture buttonHighlightTexture;

    Vector2f buttonPos;
    Vector2f buttonSize;

    MainMenuSprites();
};

#endif // PVZSPRITES_HPP