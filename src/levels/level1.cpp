#include "levels/Level1.hpp"
#include "NullActor.hpp"
#include "zombies/RegularZombie.hpp"

namespace PvZ {

    Level1::Level1() : Level{ 3 } {
        background.setTexture(backgroundTexture);
        topbar.setPosition(topbarPos);

        actors.emplace_front(new NullActor);
        //actors.emplace_front(new RegularZombie{ 1000ms });
    }

    Level1::~Level1() {
        for (auto actor : actors) {
            delete actor;
        }
    }

    GameState Level1::play() {
        drawSprite(background);
        drawSprite(topbar);

        // bool zombieLeft{false};
        for (auto it{ actors.begin() }; it != actors.end();) {
            if (!(*it)->action()) {
                delete* it;
                it = actors.erase(it);
            } else {
                ++it;
            }
            // else if ((*it)->isZombie()) {
            //     zombieLeft = true;s
            // }
        }
        // if (!zombieLeft) {
        //     return GameState::GAME_WIN;
        // }

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