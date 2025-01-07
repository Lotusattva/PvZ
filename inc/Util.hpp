#ifndef UTIL_HPP
#define UTIL_HPP

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <ranges>

#include "PathToRes.hpp"

/*
This header provides a series of utility functions and variables that are used throughout the project.
*/

namespace PvZ {

    using namespace std;
    using ms = chrono::milliseconds;
    using clk = chrono::steady_clock;
    using time_point = chrono::time_point<clk>;
    using namespace sf;

    /**
     * @brief Returns a range of numbers from start (inclusive) to end (exclusive)
     */
    constexpr inline auto range = [](auto start, auto end) { return ranges::views::iota(start, end); };

    /**
     * @brief Global window variable. Everything should be drawn to this window.
     */
    inline RenderWindow window;

    inline const string RES_PATH{ RES_PATH_CHAR_ARR };

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
    void drawSprite(Sprite&& sprite, const Vector2f& position);

    /**
     * @brief Draws a sprite at its current position. Default position is (0, 0)
     *
     * @param sprite
     */
    void drawSprite(const Sprite& sprite);

    struct Rectangle {
        Vector2f position; // top left corner
        Vector2f size;
    };

    /**
     * @brief Checks whether the mouse is hovering over a given rectangular area
     *
     * @param rectangle
     * @return true if the mouse is hovering over the area, false otherwise
     */
    bool hoverOverRectangle(const Rectangle& rectangle);

    /**
     * @brief Checks whether a point is inside a rectangle
     *
     * @param point
     * @param rectangle
     * @return true if the point is inside the rectangle, false otherwise
     */
    bool inRectangle(const Vector2f& point, const Rectangle& rectangle);

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
    void setWindow(Vector2u windowSize, short frameRate, bool VSync, bool customCursor);

    constexpr inline chrono::duration<double, std::ratio<1, 12>> frameInterval{ 1.0 }; // FIXME: find the correct value/ratio

    class Frames {
    private:
        short currentFrame{ 0 };
        const size_t frameCount;
        time_point lastFrame{ clk::now() };
        const vector<Texture>& textures;

    public:
        Frames(const vector<Texture>& textures);
        Frames(const Frames&) = delete;
        Frames(Frames&&) = delete;
        ~Frames() = default;

        Sprite getFrame();
    };
}

#endif // UTIL_HPP