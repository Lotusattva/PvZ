#ifndef PLANT_HPP
#define PLANT_HPP

#include "Actor.hpp"
#include "levels/Level.hpp"

namespace PvZ {

    /**
     * @brief Base class for plants
     */
    class Plant : public Actor {
    private:
        static inline const Vector2f hitbox{ 75.f, 75.f }, center{ 37.5f, 37.5f };
    public:
        enum class Type {
            SUNFLOWER,
            PEASHOOTER,
            WALLNUT,
            CHERRYBOMB
        };

        Plant(short health, short col, short row) :
            Actor{ health, Level::gridOrigin + Vector2f{col * Level::cellWidth, row * Level::cellHeight}, hitbox, center } {}
        Plant(const Plant&) = delete;
        Plant(Plant&&) = delete;
        virtual ~Plant() = default;

        Actor::Type getType() const override { return Actor::Type::PLANT; }
    };

    Plant* createPlant(Plant::Type plantType);

}

#endif // PLANT_HPP