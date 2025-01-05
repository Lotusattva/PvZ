#ifndef NULLACTOR_HPP
#define NULLACTOR_HPP

#include "Actor.hpp"

namespace PvZ {
    /**
     * @brief Null actor for debugging purposes
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
        const Rectangle getHitbox() const override { return { position, {0.f, 0.f} }; }
        const Vector2f getCenter() const override { return position; }
    };
}

#endif // NULLACTOR_HPP