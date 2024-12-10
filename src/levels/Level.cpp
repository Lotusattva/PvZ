#include "levels/Level.hpp"
#include "levels/Level1.hpp"

namespace PvZ {
    Level* Level::makeLevel(LevelState levelState) {
        switch (levelState) {
            case LevelState::LEVEL1:
                return new Level1();
            default:
                return nullptr;
        }
    }
}