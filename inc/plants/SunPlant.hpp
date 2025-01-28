#ifndef SUNPLANT_HPP
#define SUNPLANT_HPP

#include "Plant.hpp"
#include <chrono>
#include <string>

namespace PvZ {

    using ms = std::chrono::milliseconds;

    class SunPlant : public Plant {
    private:
        const short sunProduction;
        const ms cooldown;
        ms lastProductionTime;
        bool active;

    public:
        SunPlant(short health, short column, short sunProduction, ms cooldown);
        SunPlant(const SunPlant&) = delete;
        SunPlant(SunPlant&&) = delete;
        virtual ~SunPlant() = default;

        virtual short produceSun();
        void activate();
        void deactivate();
        bool isActive() const;

        short getSunProduction() const;
        ms getCooldown() const;
        ms getTimeUntilNextProduction() const;
        void resetProductionTimer();

        std::string getStatus() const;
    };

} // namespace PvZ

#endif // SUNPLANT_HPP