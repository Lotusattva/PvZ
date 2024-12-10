#ifndef STAGE_HPP
#define STAGE_HPP

#include "Util.hpp"

namespace PvZ {


    class Stage {
    public:
        virtual ~Stage() = default;

        virtual GameState play(Event& event) = 0;
    };

}
#endif // STAGE_HPP