#ifndef PLANT_HPP
#define PLANT_HPP

#include "Actor.hpp"
#include "levels/Level.hpp"


namespace PvZ {

    /**
     * @brief Base class for plants
     */
    class Plant : public Actor {
    protected:
        static constexpr inline Vector2f size{ 75.f, 75.f }, centerOffset{ 37.5f, 37.5f };
    public:
        enum class Type {
            PEASHOOTER
        };

        Plant(short health, short col, short row) :
            Actor{ {col * Level::cellWidth + Level::gridOrigin.x, row * Level::cellHeight + Level::gridOrigin.y}, health } {}
        Plant(const Plant&) = delete;
        Plant(Plant&&) = delete;
        virtual ~Plant() = default;

        Actor::Type getType() const override { return Actor::Type::PLANT; }

        Plant* create(Plant::Type plantType, short col, short row);
    };

}

#endif // PLANT_HPP