#ifndef SUNPLANT_HPP
#define SUNPLANT_HPP

#include "Plant.hpp"

namespace PvZ {

    /**
     * @brief Base class for sun-producing plants
     */
    class SunPlant : public Plant {
    private:
        const short int sunProduction;
        const short int cooldown;
    public:
        SunPlant(short int health, short int col, short int sunProduction, short int cooldown) :
            Plant(health, col), sunProduction(sunProduction), cooldown(cooldown) { }
        virtual ~SunPlant() = default;

        /**
         * @brief plant produces sun
         */
        virtual void produceSun();
    };
}

#endif // SUNPLANT_HPP