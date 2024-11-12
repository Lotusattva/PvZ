#ifndef PVZ_HPP
#define PVZ_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class PvZ {

private:
    struct Settings;

    struct MainMenuSprites;

    struct spriteDimensions;

    Settings* settings;
    MainMenuSprites* sprites;
    spriteDimensions* dimensions;

    bool overButton(Vector2f* buttonPos, Vector2f* buttonSize);

protected:
    bool PAUSE;
    RenderWindow window;
    Event event;

    /**
     *@brief Draws a sprite at a given position
     * 
     * @param sprite 
     * @param position 
     */
    void drawSprite(Sprite* sprite, Vector2f position);

    /**
     *@brief Draws a sprite at its current position. Default position is (0, 0)
     * 
     * @param sprite 
     */
    void drawSprite(Sprite* sprite);

public:
    PvZ();
    void run();
};

#endif // PVZ_HPP