#include "levels/Level1.hpp"
#include "NullActor.hpp"

namespace PvZ {
    class Level1::Sprites {
    private:
        Texture backgroundTexture;
        Texture topbarTexture;
    public:
        Sprite background;
        Sprite topbar;

        Vector2f topbarPos;
        Vector2f topbarSize;

        Sprites();
    };

    Level1::Sprites::Sprites() {
        topbarPos = { 280.f, 0.f };
        topbarSize = { 522.f, 87.f };

        backgroundTexture.loadFromFile("res/img/level/frontyard_3row.jpg");
        background.setTexture(backgroundTexture);

        topbarTexture.loadFromFile("res/img/topbar/bar4.png");
        topbar.setTexture(topbarTexture);
        topbar.setPosition(topbarPos);
    }


    Level1::Level1() : sprites(new Sprites), Level(3) {
        actors.emplace_front(new NullActor);
        actors.emplace_front(new NullActor);
    }

    Level1::~Level1() {
        delete sprites;
        for (auto actor : actors) {
            delete actor;
        }
    }

    GameState Level1::play(Event& event) {
        drawSprite(sprites->background);
        drawSprite(sprites->topbar);
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    return GameState::MAIN_MENU;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Escape) {
                        return GameState::MAIN_MENU;
                    }
                default:
                    break;
            }
        }
        // bool zombieLeft{false};
        for (auto it{ actors.before_begin() }; it != actors.end(); ++it) {
            if (!(*it)->action()) {
                delete* it;
                it = actors.erase_after(it);
            }
        }
        // if (!zombieLeft) {
        //     return GameState::GAME_WIN;
        // }
        return GameState::PLAY;
    }
}