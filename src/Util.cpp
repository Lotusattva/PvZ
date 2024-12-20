#include "Util.hpp"

namespace PvZ {
    bool hoverOverArea(const Vector2f& spritePos, const Vector2f& spriteSize) {
        auto mousePos = Mouse::getPosition(window);
        return mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
            mousePos.y >= spritePos.y && mousePos.y <= spritePos.y + spriteSize.y;
    }

    void drawSprite(Sprite& sprite, const Vector2f& position) {
        sprite.setPosition(position);
        window.draw(sprite);
    }

    void drawSprite(const Sprite& sprite) {
        window.draw(sprite);
    }

    Cursor& getCustomCursor(bool useCustomCursor) {
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

    void setWindow(Vector2u windowSize, short frameRate, bool VSync, bool customCursor) {
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
        auto desktop = VideoMode::getDesktopMode();
        auto posX = (desktop.width - windowSize.x) / 2;
        auto posY = (desktop.height - windowSize.y) / 2;
        window.setPosition(Vector2i(posX, posY));
    }

    Frames::Frames(const short frameCount, const Texture textures[]) :
        frameCount{ frameCount }, currentFrame{ 0 }, sprites{ new Sprite[frameCount] }, lastFrame(clk::now()) {
        for (short i = 0; i < frameCount; ++i) {
            sprites[i].setTexture(textures[i]);
        }
    }

    Frames::~Frames() {
        delete[] sprites;
    }

    const Sprite& Frames::getFrame(Vector2f& position) {
        auto now = clk::now();
        if (now - lastFrame >= frameInterval) {
            lastFrame = now;
            currentFrame = (currentFrame + 1) % frameCount;
        }
        sprites[currentFrame].setPosition(position);
        return sprites[currentFrame];
    }
}
