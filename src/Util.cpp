#include "Util.hpp"

namespace PvZ {
    bool hoverOverRectangle(const Rectangle& rectangle) {
        Vector2i mousePos{ Mouse::getPosition(window) };
        Vector2f mousePosF{ static_cast<float>(mousePos.x), static_cast<float>(mousePos.y) };
        return inRectangle(mousePosF, rectangle);
    }

    bool inRectangle(const Vector2f& point, const Rectangle& rectangle) {
        return point.x >= rectangle.position.x && point.x <= rectangle.position.x + rectangle.size.x &&
            point.y >= rectangle.position.y && point.y <= rectangle.position.y + rectangle.size.y;
    }

    void drawSprite(Sprite&& sprite, const Vector2f& position) {
        sprite.setPosition(position);
        window.draw(sprite);
    }

    void drawSprite(const Sprite& sprite) {
        window.draw(sprite);
    }

    Cursor& getCustomCursor(bool useCustomCursor) {
        if (!useCustomCursor) {
            static Cursor cursor{ Cursor::Type::Arrow };
            return cursor;
        }

        Image cursorImage(RES_PATH + "img/cursor/spike.png");
        static Cursor cursor{ cursorImage.getPixelsPtr(), cursorImage.getSize(), { 0u,0u } };
        return cursor;
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


    Frames::Frames(const vector<Texture>& textures) : frameCount{ textures.size() }, textures{ textures } {}

    Sprite Frames::getFrame() {
        auto now{ clk::now() };
        if (now - lastFrame >= frameInterval) {
            lastFrame = now;
            currentFrame = (currentFrame + 1) % frameCount;
        }
        return Sprite{ textures.at(currentFrame) };
    }
}
