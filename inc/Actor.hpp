#ifndef ACTOR_HPP
#define ACTOR_HPP

class Actor {
private:
    short int health;
    bool isAlive;
protected:
    Actor(short int health) : health(health), isAlive(false) {}
    virtual ~Actor() = 0 {}

    /**
     * @brief actor performs an action
     * 
     * @return true if the action was successful
     * @return false if the actor is dead
     */
    virtual bool action();

    /**
     * @brief actor takes damage
     * 
     * @param damage
     */
    virtual void takeDamage(short int damage);
};

#endif // ACTOR_HPP