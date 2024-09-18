#pragma once
#include "Entity.h"

class Character: public Entity
{
public:
    int getLife() const;

private:
    int life = 1;
    int direction = 0;

public:
    void move() const;
    void setDirection(int direction);
    int getDirection() const;
    void attack(int damage) const;
    void receiveDamage(int damage);
    bool checkIsDead() const;
    void update() override;
};
