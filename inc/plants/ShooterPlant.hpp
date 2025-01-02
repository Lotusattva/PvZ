#ifndef SHOOTER_PLANT_HPP
#define SHOOTER_PLANT_HPP

#include "Plant.hpp"
#include "Projectile.hpp"

namespace PvZ {

    /**
     * @brief Base class for plants that shoot projectiles
     */
    class ShooterPlant : public Plant {
    private:
        const Projectile::Type projectileType;
        const short attackRange;
        const ms cooldown;
        time_point lastShot;

        /**
        * @brief Updates the last shot time to the current time
        */
        void updateLastShot() { lastShot = clk::now(); }

        /**
        * @brief Checks if an actor is within range of the plant
        *
        * @param actor
        * @return true if the actor is within range
        */
        bool withInRange(Actor* actor) const;

    public:
        ShooterPlant(short health, short col, short row, Projectile::Type projectileType, short attackRange, ms cooldown) :
            Plant{ health, col, row }, projectileType{ projectileType }, attackRange{ attackRange }, cooldown{ cooldown }, lastShot{ clk::now() } {}
        ShooterPlant(const ShooterPlant&) = delete;
        ShooterPlant(ShooterPlant&&) = delete;
        virtual ~ShooterPlant() = default;

        /**
         * @brief plant shoots a projectile
         */
        virtual void shoot() = 0;

        /**
         * @brief Get the range of the plant
         *
         * @return the range of the plant
         */
        const short getRange() const { return attackRange; }

        /**
         * @brief Checks if the plant is on cooldown
         *
         * @return true if the plant is on cooldown
         */
        bool onCooldown() const { return clk::now() - lastShot < cooldown; }

    };
}

#endif // SHOOTER_PLANT_HPP