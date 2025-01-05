#ifndef PEA_HPP
#define PEA_HPP

#include "Projectile.hpp"
namespace PvZ {

    class Pea : public Projectile {
    private:
        static constexpr inline short peaDamage{ 1 };
    public:
        Pea(Vector2f& position) : Projectile{ position, peaDamage } {}
        Pea(const Pea&) = delete;
        Pea(Pea&&) = delete;
        ~Pea() = default;

        bool action() override;
        void takeDamage(short) override { return; }
        bool inRange(const Actor* const other) const override;
        const Rectangle getHitbox() const override;
        const Vector2f getCenter() const override;
        Actor::Type getType() const override { return Actor::Type::PROJECTILE; }
    };

}


#endif // PEA_HPP