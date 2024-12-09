#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "Stage.hpp"

namespace PvZ {

    class MainMenu : public Stage {
    protected:
        class Sprites;

        Sprites* sprites;
    public:
        MainMenu();
        ~MainMenu();
        GameState play(Event& event) override;
    };
}

#endif // MAINMENU_HPP