#ifndef STAGE_HPP
#define STAGE_HPP

#include "Util.hpp"

namespace PvZ {

    /**
     * @brief Abstract base class for GUI
     */
    class Stage {
    public:
        Stage() = default;
        Stage(const Stage&) = delete;
        Stage(Stage&&) = delete;
        virtual ~Stage() = default;

        /**
         * @brief Handle events, draw sprites, and update game state.
         * This is the method to be called in each iteration of the main game loop.
         */
        virtual GameState play(Event& event) = 0;
    };

}
#endif // STAGE_HPP