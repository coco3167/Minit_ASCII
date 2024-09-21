#pragma once

#include "InteractableEntity.h"

class Character: public InteractableEntity
{
public:
    using InteractableEntity::InteractableEntity;

    // Getter
    int getLife() const;
    int getDirection() const;
    int getHorizontalSpeed() const;
    int getVerticalSpeed() const;
    bool checkIsDead() const;
    int getDamage() const;

    // Setter
    void setDirection(int direction);
    void setDamage(int damage);
    void moveHorizontal(int moveHorizontalSpeed);
    void moveVertical(int moveVertivalSpeed);
    void receiveDamage(int damage);
    
    //void attack(int damage) const;
    
    void update(EntityManager& entity_manager) override;
    void onInteract(Entity* interactor) override;
    virtual void DeathEvent();
    
private:
    int life = 1;
    int direction = 0;
    int horizontalSpeed = 2;
    int verticalSpeed = 1;
    int damage = 0;
    //bool dead = false;
};
