#include "levels/Level1.hpp"
#include "NullActor.hpp"
#include "zombies/RegularZombie.hpp"
#include "plants/projectiles/Pea.hpp"

namespace PvZ {

    Level1::Level1() : Level{ 3 } {
        background.setTexture(backgroundTexture);
        topbar.setPosition(topbarPos);

        actors.emplace_front(new NullActor);
        // auto position = Vector2f{ 100.f, 100.f };
        actors.emplace_front(new Pea(Vector2f{ 300.f, 350.f }));
        actors.emplace_front(new RegularZombie{ 1000ms, 2 });
    }

    Level1::~Level1() {
        for (auto actor : actors) {
            delete actor;
        }
    }

    GameState Level1::play() {
        drawSprite(background);
        drawSprite(topbar);

        for (auto it{ actors.begin() }; it != actors.end();) {
            if (!(*it)->action()) {
                delete* it;
                it = actors.erase(it);
            } else {
                ++it;
            }
        }

        while (const auto event{ window.pollEvent() }) {
            if (event->is<Event::Closed>()) {
                window.close();
                return GameState::MAIN_MENU;
            }
            if (const auto * keyPressed{ event->getIf<Event::KeyPressed>() }) {
                if (keyPressed->scancode == Keyboard::Scancode::Escape) {
                    window.close();
                    return GameState::MAIN_MENU;
                }
            }
        }

        return GameState::PLAY;
    }
}