#ifndef PLANT_HPP
#define PLANT_HPP

#include "Actor.hpp"

enum class PlantType {
    SUNFLOWER,
    PEASHOOTER,
    WALLNUT,
    CHERRYBOMB
};

class Plant : public Actor {
private:
    const short int col;
    const short int row;
protected:
    Plant(short int health, short int col, short int row) : Actor(health), col(col), row(row) {}
    virtual ~Plant() = 0 {}
};

Plant* createPlant(PlantType plantType);

#endif // PLANT_HPP