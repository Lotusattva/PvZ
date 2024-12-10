#ifndef NULLACTOR_HPP
#define NULLACTOR_HPP

#include "Actor.hpp"

namespace PvZ {
    class NullActor : public Actor {
    public:
        NullActor() : Actor(0) { }
        ~NullActor() = default;
        bool action() override { return true; }
    };
}

#endif // NULLACTOR_HPP