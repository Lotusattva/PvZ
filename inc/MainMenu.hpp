#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "Stage.hpp"

namespace PvZ {

    /**
     * @brief Main menu GUI
     */
    class MainMenu : public Stage {
    protected:
        const Texture backgroundTexture{ "res/img/mainMenu/mainMenu.png" },
            buttonTexture{ "res/img/mainMenu/button.png" },
            buttonHighlightTexture{ "res/img/mainMenu/buttonHighlight.png" };

        Sprite background{ backgroundTexture },
            button{ buttonTexture },
            buttonHighlight{ buttonHighlightTexture };
        const Vector2f buttonPos{ 480.f, 80.f }, buttonSize{ 331.f, 145.f };

    public:
        MainMenu();
        MainMenu(const MainMenu&) = delete;
        MainMenu(MainMenu&&) = delete;
        ~MainMenu() = default;

        GameState play() override;
    };
}

#endif // MAINMENU_HPP