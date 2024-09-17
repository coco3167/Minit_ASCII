#include "Character.h"

#include <iostream>

#include "Direction.h"

/*
====================
Getter
====================
*/

int Character::getLife()
{
    return life;
}

void Character::move(int direction)
{
    if (canMove(direction))
    {
        std::cout << direction << "\n";
    }
}

bool Character::canMove(int direction)
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

