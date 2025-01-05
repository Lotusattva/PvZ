#ifndef SUNPLANT_HPP
#define SUNPLANT_HPP

#include "Plant.hpp"

namespace PvZ {

    /**
     * @brief Base class for sun-producing plants
     */
    class SunPlant : public Plant {
    private:
        const short sunProduction;
        const ms cooldown;
    public:
        SunPlant(short health, short col, short row, short sunProduction, ms cooldown) :
            Plant{ health, col, row }, sunProduction{ sunProduction }, cooldown{ cooldown } {}
        SunPlant(const SunPlant&) = delete;
        SunPlant(SunPlant&&) = delete;
        virtual ~SunPlant() = default;

        /**
         * @brief plant produces sun
         */
        virtual void produceSun();
    };
}

#endif // SUNPLANT_HPP