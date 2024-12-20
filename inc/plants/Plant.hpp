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
        const short col;
    public:
        Plant(short health, short col) : Actor{ health }, col{ col } {}
        Plant(const Plant&) = delete;
        Plant(Plant&&) = delete;
        virtual ~Plant() = default;

        const short getCol() const { return col; }
    };

    Plant* createPlant(PlantType plantType);
}

#endif // PLANT_HPP