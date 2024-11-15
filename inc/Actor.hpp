#ifndef ACTOR_HPP
#define ACTOR_HPP

class Actor {
private:
    short int health;
    bool alive;
public:
    Actor(short int health) : health(health), alive(false) {}
    virtual ~Actor() = default;

    /**
     * @brief actor performs an action
     * 
     * @return true if the action was successful
     * @return false if the actor is dead
     */
    virtual void action() = 0;

    /**
     * @brief actor takes damage
     * 
     * @param damage
     */
    virtual void takeDamage(short int damage) {
        health -= damage;
        if (health <= 0) {
            alive = false;
        }
    }

    bool isAlive() const { return alive; }
};

#endif // ACTOR_HPP