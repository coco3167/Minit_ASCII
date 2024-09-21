#pragma once
#include "Entity.h"

class Character: public Entity
{
public:
    using Entity::Entity;

    // Getter
    int getLife() const;
    int getDirection() const;
    int getHorizontalSpeed() const;
    int getVerticalSpeed() const;

    // Setter
    void setDirection(int direction);
    
    void moveHorizontal(int moveHorizontalSpeed);
    void moveVertical(int moveVertivalSpeed);
    void receiveDamage(int damage);
    bool checkIsDead() const;
    //void attack(int damage) const;
    void update(EntityManager& entity_manager) override;

    virtual void DeathEvent(EntityManager const& entity_manager);
    
private:
    int life = 1;
    int direction = 0;
    int horizontalSpeed = 2;
    int verticalSpeed = 1;
    //bool dead = false;
};
