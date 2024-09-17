#pragma once
#include "Entity.h"

class Character: public Entity
{
public:
    int getLife();

private:
    int life = 1;
    
    virtual void move(int direction) = 0;
    virtual bool canMove(int direction) = 0;
    virtual void attack(int damage) = 0;
    
    
};
