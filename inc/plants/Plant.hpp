#ifndef PLANT_HPP
#define PLANT_HPP

#include "../Actor.hpp"

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
    Plant(RenderWindow* window, short int health, short int col) : Actor(window, health), col(col) {}
    virtual ~Plant() = default;

    short int getCol() const { return col; }
};

Plant* createPlant(RenderWindow* window, PlantType plantType);

#endif // PLANT_HPP