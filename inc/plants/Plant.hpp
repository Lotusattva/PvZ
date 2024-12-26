#ifndef PLANT_HPP
#define PLANT_HPP

#include "Actor.hpp"

namespace PvZ {

    /**
     * @brief Base class for plants
     */
    class Plant : public Actor {
    private:
        const short row;
    public:
        enum class Type {
        SUNFLOWER,
        PEASHOOTER,
        WALLNUT,
        CHERRYBOMB
        };

        Plant(short health, short row) : Actor{ health }, row{ row } {}
        Plant(const Plant&) = delete;
        Plant(Plant&&) = delete;
        virtual ~Plant() = default;

        Actor::Type getType() const override { return Actor::Type::PLANT; }
    };

    Plant* createPlant(Plant::Type plantType);

}

#endif // PLANT_HPP