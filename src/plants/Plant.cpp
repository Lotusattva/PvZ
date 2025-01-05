#include "plants/Plant.hpp"
#include "plants/Peashooter.hpp"

namespace PvZ {
    Plant* Plant::create(Plant::Type plantType, short col, short row) {
        switch (plantType) {
            case Type::PEASHOOTER:
                return new Peashooter{ col, row };
            default:
                return nullptr;
        }
    }
}