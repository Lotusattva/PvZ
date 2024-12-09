#ifndef NULLPLANT_HPP
#define NULLPLANT_HPP

#include "Plant.hpp"

class NullPlant : public Plant {
public:
    NullPlant() : Plant(nullptr, 0, 0) { }
    ~NullPlant() = default;

    bool action() override { return true; }
};

#endif // NULLPLANT_HPP