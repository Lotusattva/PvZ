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

class Level1Sprites {
public:
    Sprite background;
    Texture backgroundTexture;

    Sprite topbar;
    Texture topbarTexture;
    Vector2f topbarPos;
    Vector2f topbarSize;

    Level1Sprites();
};

#endif // PVZSPRITES_HPP