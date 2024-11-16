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
    const short int row;
public:
    Plant(RenderWindow* window, short int health, short int col, short int row) : Actor(window, health), col(col), row(row) {}
    virtual ~Plant() = default;

    short int getCol() const { return col; }
    short int getRow() const { return row; }
};

Plant* createPlant(RenderWindow* window, PlantType plantType);

#endif // PLANT_HPP