#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "Stage.hpp"

namespace PvZ {

    /**
     * @brief Main menu GUI
     */
    class MainMenu : public Stage {
    protected:
        class Sprites {
        private:
            Texture backgroundTexture, buttonTexture, buttonHighlightTexture;

        public:
            Sprite background, button, buttonHighlight;
            static inline const Vector2f buttonPos{ 480.f, 80.f }, buttonSize{ 331.f, 145.f };
            Sprites();
            Sprites(const Sprites&) = delete;
            Sprites(Sprites&&) = delete;
            ~Sprites() = default;
        };

        Sprites* const sprites{ new Sprites };
    public:
        MainMenu() = default;
        MainMenu(const MainMenu&) = delete;
        MainMenu(MainMenu&&) = delete;
        ~MainMenu();
        GameState play(Event& event) override;
    };
}

#endif // MAINMENU_HPP