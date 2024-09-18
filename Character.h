﻿#pragma once
#include "Entity.h"

class Character: public Entity
{
public:
    using Entity::Entity;

    // Getter
    int getLife() const;
    int getDirection() const;

    // Setter
    void setDirection(int direction);
    
    void move();
    void attack(int damage) const;
    void receiveDamage(int damage);
    bool checkIsDead() const;
    void update(EntityManager const& entity_manager) override;

    
private:
    int life = 1;
    int direction = 0;
    
};
