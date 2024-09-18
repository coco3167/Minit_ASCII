#include "Character.h"

#include <iostream>

#include "Direction.h"

/*
====================
Getter
====================
*/

int Character::getLife() const
{
    return life;
}

void Character::move() const
{
    if(direction == 0)
        return;
    
    if (canMove())
    {
        std::cout << direction << "\n";
    }
}

bool Character::canMove() const
{
    if (direction == LEFT)
    {
        //TEST COLLISION WITH LEFT
    }

    if (direction == RIGHT)
    {
        //TEST COLLISION WITH RIGHT
    }

    if (direction == UP)
    {
        //TEST COLLISION WITH UP
    }

    if (direction == DOWN)
    {
        //TEST COLLISION WITH DOWN
    }

    return true;
}

void Character::setDirection(int direction)
{
    this->direction = direction;
}

