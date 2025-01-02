#ifndef NULLACTOR_HPP
#define NULLACTOR_HPP

#include "Actor.hpp"

namespace PvZ {
    /**
     * @brief Null actor for placeholders after plants and zombies die
     */
    class NullActor : public Actor {
    public:
        NullActor() = default;
        NullActor(const NullActor&) = delete;
        NullActor(NullActor&&) = delete;
        ~NullActor() = default;
        bool action() override { return true; }
        bool inRange(const Actor*) const override { return false; }
        Actor::Type getType() const override { return Actor::Type::NULL_ACTOR; }
    };
}

#endif // NULLACTOR_HPP