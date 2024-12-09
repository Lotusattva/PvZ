#ifndef STAGE_HPP
#define STAGE_HPP

#include <SFML/Graphics.hpp>
#include "PvZ.hpp"

using namespace sf;

class Stage {
protected:

    static RenderWindow window;

    /**
    * @brief Draws a sprite at a given position
    *
    * @param sprite
    * @param position
    */
    static void drawSprite(Sprite& sprite, const Vector2f& position);

    /**
     * @brief Draws a sprite at its current position. Default position is (0, 0)
     *
     * @param sprite
     */
    static void drawSprite(const Sprite& sprite);

    static bool hoverOverArea(const Vector2f& buttonPos, const Vector2f& buttonSize);

    static Cursor& getCustomCursor(bool useCustomCursor);

public:

    static void setWindow(Vector2u windowSize, short int frameRate, bool VSync, bool customCursor);

    virtual ~Stage() = default;

    virtual GameState play(Event& event) = 0;

    friend class PvZ;
};

#endif // STAGE_HPP