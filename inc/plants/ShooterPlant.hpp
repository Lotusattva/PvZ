#ifndef SHOOTER_PLANT_HPP
#define SHOOTER_PLANT_HPP

#include "Plant.hpp"
#include "projectiles/Projectile.hpp"

namespace PvZ {

    /**
     * @brief Base class for plants that shoot projectiles
     */
    class ShooterPlant : public Plant {
    protected:
        const Projectile::Type projectileType;
        const short attackRange; // unit: number of cells
        const ms attackInterval;
        time_point lastAttack{ clk::now() };

        /**
        * @brief Updates the last shot time to the current time
        */
        void updateLastShot() { lastAttack = clk::now(); }

        constexpr static inline auto isZombie = [](Actor* actor) { return actor->getType() == Actor::Type::ZOMBIE; };
    public:
        ShooterPlant(short health, short col, short row, Projectile::Type projectileType, short attackRange, ms attackInterval) :
            Plant{ health, col, row }, projectileType{ projectileType }, attackRange{ attackRange }, attackInterval{ attackInterval } {}
        ShooterPlant(const ShooterPlant&) = delete;
        ShooterPlant(ShooterPlant&&) = delete;
        virtual ~ShooterPlant() = default;

        const Rectangle getHitbox() const override { return { {position.x + Plant::size.x, position.y}, {attackRange * Level::cellWidth, Plant::size.y} }; }
        const Vector2f getCenter() const override { return position + centerOffset; }

        bool action() override;

        virtual void shoot() = 0;
        virtual Frames& getFrames() = 0;
    };
}

#endif // SHOOTER_PLANT_HPP