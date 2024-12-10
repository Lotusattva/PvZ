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

    class Plant : public Actor {
    private:
        const short int col;
    public:
        Plant(short int health, short int col) : Actor(health), col(col) { }
        virtual ~Plant() = default;

        short int getCol() const { return col; }
    };

    Plant* createPlant(PlantType plantType);
}

#endif // PLANT_HPP