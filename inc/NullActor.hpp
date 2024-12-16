#ifndef NULLACTOR_HPP
#define NULLACTOR_HPP

#include "Actor.hpp"

namespace PvZ {
    /**
     * @brief Null actor for placeholders after plants and zombies die
     */
    class NullActor : public Actor {
    public:
        NullActor() : Actor{ 0, false } {}
        ~NullActor() = default;
        bool action() override { return true; }
    };
}

#endif // NULLACTOR_HPP