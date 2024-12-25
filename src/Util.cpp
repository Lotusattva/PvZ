#include "Util.hpp"

namespace PvZ {
    bool hoverOverArea(const Vector2f& spritePos, const Vector2f& spriteSize) {
        auto mousePos{ Mouse::getPosition(window) };
        return mousePos.x >= spritePos.x && mousePos.x <= spritePos.x + spriteSize.x &&
            mousePos.y >= spritePos.y && mousePos.y <= spritePos.y + spriteSize.y;
    }

    void drawSprite(Sprite&& sprite, const Vector2f&& position) {
        sprite.setPosition(position);
        window.draw(sprite);
    }

    void drawSprite(const Sprite& sprite) {
        window.draw(sprite);
    }

    Cursor getCustomCursor(bool useCustomCursor) {
        if (!useCustomCursor) {
            return Cursor{ Cursor::Type::Arrow };
        }

        Image cursorImage(RES_PATH + "img/cursor/spike.png");
        return Cursor{ cursorImage.getPixelsPtr(), cursorImage.getSize(), { 0u,0u } };
    }

    void setWindow(Vector2u windowSize, short frameRate, bool VSync, bool customCursor) {
        window.create(VideoMode{ windowSize }, "PvZ", Style::Close | Style::Titlebar);
        window.setFramerateLimit(frameRate);
        window.setVerticalSyncEnabled(VSync);
        window.setMouseCursor(getCustomCursor(customCursor));
        auto [desktopWidth, desktopHeight] = VideoMode::getDesktopMode().size;
        auto posX{ (desktopWidth - windowSize.x) / 2 };
        auto posY{ (desktopHeight - windowSize.y) / 2 };
        window.setPosition(Vector2i(posX, posY));
    }


    Frames::Frames(const vector<Sprite>* const sprites) : frameCount{ sprites->size() }, sprites{ sprites } {}

    Sprite Frames::getFrame() {
        auto now{ clk::now() };
        if (now - lastFrame >= frameInterval) {
            lastFrame = now;
            currentFrame = (currentFrame + 1) % frameCount;
        }
        return Sprite{ sprites->at(currentFrame) };
    }
}
