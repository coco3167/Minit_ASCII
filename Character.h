#pragma once
#include "Entity.h"

class Character: public Entity
{
public:
    int getLife() const;

private:
    int life = 1;

public:
    void move(int direction) const;
    bool canMove(int direction) const;
    void attack(int damage) const;
    void receiveDamage(int damage) const;
};
