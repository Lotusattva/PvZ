#include "CustomCursor.hpp"
#include <iostream>
#include <filesystem>
#include <SFML/Graphics/Image.hpp>

Cursor& getCustomCursor(bool useCustomCursor) {
    if (!useCustomCursor) {
        static Cursor defaultCursor;
        defaultCursor.loadFromSystem(Cursor::Arrow);
        return defaultCursor;
    }
    Image cursorImage;
    if (!cursorImage.loadFromFile("res/img/cursor/spike.png")) {
        std::cerr << "Error: Unable to load cursor image from 'res/img/cursor/spike.png'" << std::endl;
        std::cerr << "Current working directory: " << std::filesystem::current_path() << std::endl;
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