#pragma once
#include "Entity.h"

class Character: public Entity
{
public:
    int getLife();

private:
    int life = 1;

public:
    void move(int direction);
    bool canMove(int direction);
    void attack(int damage);
};
