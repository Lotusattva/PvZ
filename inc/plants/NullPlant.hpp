#ifndef NULLPLANT_HPP
#define NULLPLANT_HPP

#include "Plant.hpp"

namespace PvZ {
    class NullPlant : public Plant {
    public:
        NullPlant() : Plant(0, 0) { }
        ~NullPlant() = default;

        bool action() override { return true; }
    };
}

#endif // NULLPLANT_HPP