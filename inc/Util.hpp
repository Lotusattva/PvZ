#ifndef UTIL_HPP
#define UTIL_HPP

#include <SFML/Graphics.hpp>
#include <chrono>
#include <vector>
#include <iostream>

using namespace std;
using ms = chrono::milliseconds;
using clk = chrono::steady_clock;
using time_point = chrono::time_point<clk>;
using namespace sf;

typedef unsigned short ushort;

/*
This header provides a series of utility functions and variables that are used throughout the project.
*/

namespace PvZ {

    /**
     * @brief Global window variable. Everything should be drawn to this window.
     */
    inline RenderWindow window;

    enum class GameState {
        MAIN_MENU,
        PLAY,
        GAME_WIN,
        GAME_LOSE
    };

    enum class LevelState {
        LEVEL1
    };

    /**
        * @brief Draws a sprite at a given position
        *
        * @param sprite
        * @param position
        */
    void drawSprite(Sprite& sprite, const Vector2f& position);

    /**
     * @brief Draws a sprite at its current position. Default position is (0, 0)
     *
     * @param sprite
     */
    void drawSprite(const Sprite& sprite);

    /**
     * @brief Checks whether the mouse is hovering over a given area
     *
     * @param spritePos
     * @param spriteSize
     * @return true if the mouse is hovering over the area, false otherwise
     */
    bool hoverOverArea(const Vector2f& spritePos, const Vector2f& spriteSize);

    /**
     * @brief Returns a custom cursor if useCustomCursor is true, otherwise returns the default cursor
     *
     * @param useCustomCursor
     * @return a custom cursor if useCustomCursor is true, otherwise returns the default cursor
     */
    Cursor& getCustomCursor(bool useCustomCursor);

    /**
     * @brief Sets the window size, frame rate, VSync, and custom cursor. Constructs the window.
     */
    void setWindow(Vector2u windowSize, ushort frameRate, bool VSync, bool customCursor);
}

#endif // UTIL_HPP