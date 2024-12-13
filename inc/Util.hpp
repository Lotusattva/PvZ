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

/*
This header provides a series of utility functions and variables that are used throughout the project.
*/

namespace PvZ {

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
    inline void drawSprite(Sprite& sprite, const Vector2f& position) {
        sprite.setPosition(position);
        window.draw(sprite);
    }

    /**
     * @brief Draws a sprite at its current position. Default position is (0, 0)
     *
     * @param sprite
     */
    inline void drawSprite(const Sprite& sprite) {
        window.draw(sprite);
    }

    /**
     * @brief Checks whether the mouse is hovering over a given area
     * 
     * @param spritePos
     * @param spriteSize
     * @return true if the mouse is hovering over the area, false otherwise
     */
    inline bool hoverOverArea(const Vector2f& spritePos, const Vector2f& spriteSize) {
        Vector2i mousePos = Mouse::getPosition(window);
        return mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
            mousePos.y >= spritePos.y && mousePos.y <= spritePos.y + spriteSize.y;
    }

    /**
     * @brief Returns a custom cursor if useCustomCursor is true, otherwise returns the default cursor
     * 
     * @param useCustomCursor
     * @return a custom cursor if useCustomCursor is true, otherwise returns the default cursor
     */
    inline Cursor& getCustomCursor(bool useCustomCursor) {
        if (!useCustomCursor) {
            static Cursor defaultCursor;
            defaultCursor.loadFromSystem(Cursor::Arrow);
            return defaultCursor;
        }
        Image cursorImage;
        if (!cursorImage.loadFromFile("res/img/cursor/spike.png")) {
            std::cerr << "Error: Unable to load cursor image from 'res/img/cursor/spike.png'" << std::endl;
            static Cursor defaultCursor;
            defaultCursor.loadFromSystem(Cursor::Arrow);
            return defaultCursor;
        }
        Vector2u cursorSize = cursorImage.getSize();
        Vector2u cursorHotspot = { 0u, 0u };

        static Cursor customCursor;
        customCursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorSize, cursorHotspot);

        return customCursor;
    }

    /**
     * @brief Sets the window size, frame rate, VSync, and custom cursor. Constructs the window.
     */
    inline void setWindow(Vector2u windowSize, short frameRate, bool VSync, bool customCursor) {
        ////// Init window
        // Set window size
        window.create(VideoMode(windowSize.x, windowSize.y),
            "PvZ", Style::Close | Style::Titlebar);
        // Set frame rate
        window.setFramerateLimit(frameRate);
        // Set VSync
        window.setVerticalSyncEnabled(VSync);
        // Set custom cursor
        window.setMouseCursor(getCustomCursor(customCursor));
        // Center the window
        VideoMode desktop = VideoMode::getDesktopMode();
        int posX = (desktop.width - windowSize.x) / 2;
        int posY = (desktop.height - windowSize.y) / 2;
        window.setPosition(Vector2i(posX, posY));
    }
}

#endif // UTIL_HPP