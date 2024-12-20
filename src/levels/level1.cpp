#include "levels/Level1.hpp"
#include "NullActor.hpp"
#include "zombies/RegularZombie.hpp"

namespace PvZ {

    Level1::Sprites::Sprites() {
        backgroundTexture.loadFromFile("res/img/level/frontyard_3row.jpg");
        background.setTexture(backgroundTexture);

        topbarTexture.loadFromFile("res/img/topbar/bar4.png");
        topbar.setTexture(topbarTexture);
        topbar.setPosition(topbarPos);
    }

    Level1::Level1() : Level{ 3 } {
        actors.emplace_front(new NullActor);
        actors.emplace_front(new RegularZombie{ 1000ms });
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
        return GameState::PLAY;
    }
}