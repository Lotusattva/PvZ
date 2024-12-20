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
        Peashooter(const Peashooter&) = delete;
        Peashooter(Peashooter&&) = delete;
        ~Peashooter();

        bool action() override;
        void shoot() override;
    };
}

#endif // PEASHOOTER_HPP