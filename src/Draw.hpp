#ifndef DRAW_HPP
#define DRAW_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Draw {
private:
    RenderWindow* window;

public:

    Draw() {
        window = nullptr;
    }
    
    Draw(RenderWindow* window) {
        this->window = window;
    }

    void drawFromFile(const char* path, Vector2f position = { 0, 0 }) {
        Texture texture;
        texture.loadFromFile(path);
        Sprite sprite = Sprite(texture);
        sprite.setPosition(position);
        window->draw(sprite);
    }
    
};

#endif // DRAW_HPP