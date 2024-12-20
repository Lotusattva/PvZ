#ifndef PEASHOOTER_HPP
#define PEASHOOTER_HPP

#include "ShooterPlant.hpp"

namespace PvZ {

    /**
     * @brief Peashooter class -- to be implemented
     */
    class Peashooter : public ShooterPlant {
    public:
        Peashooter(short col);
        ~Peashooter();

        bool action() override;
        void shoot() override;
    };
}

#endif // PEASHOOTER_HPP