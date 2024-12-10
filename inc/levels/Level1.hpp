#ifndef LEVEL1_HPP
#define LEVEL1_HPP

#include "Level.hpp"

namespace PvZ {

    class Level1 : public Level {
    private:
        class Sprites;

        static vector<Row*>* makeRows();
        static Row* makeRow1();
        static Row* makeRow2();
        static Row* makeRow3();

        Sprites* sprites;
    public:

        Level1();
        ~Level1();
        GameState play(Event& event) override;
    };
}

#endif // LEVEL1_HPP