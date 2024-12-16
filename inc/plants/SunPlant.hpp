#ifndef SUNPLANT_HPP
#define SUNPLANT_HPP

#include "Plant.hpp"

namespace PvZ {

    /**
     * @brief Base class for sun-producing plants
     */
    class SunPlant : public Plant {
    private:
        const ushort sunProduction;
        const ms cooldown;
    public:
        SunPlant(short health, ushort col, ushort sunProduction, ms cooldown) :
            Plant{ health, col }, sunProduction{ sunProduction }, cooldown{ cooldown } {}
        virtual ~SunPlant() = default;

        /**
         * @brief plant produces sun
         */
        virtual void produceSun();
    };
}

#endif // SUNPLANT_HPP