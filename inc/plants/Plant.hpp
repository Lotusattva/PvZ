#ifndef PLANT_HPP
#define PLANT_HPP

#include "Actor.hpp"

namespace PvZ {

    enum class PlantType {
        SUNFLOWER,
        PEASHOOTER,
        WALLNUT,
        CHERRYBOMB
    };

    /**
     * @brief Base class for plants
     */
    class Plant : public Actor {
    private:
        const ushort col;
    public:
        Plant(short health, ushort col) : Actor{ health }, col{ col } {}
        virtual ~Plant() = default;

        const ushort getCol() const { return col; }
    };

    Plant* createPlant(PlantType plantType);
}

#endif // PLANT_HPP