#include "levels/Level.hpp"
#include "levels/Level1.hpp"

namespace PvZ {
    Level* makeLevel(LevelState levelState) {
        switch (levelState) {
            case LevelState::LEVEL1:
                currentLevel = new Level1;
                break;
            default:
                currentLevel = nullptr;
        }
        return currentLevel;
    }
}