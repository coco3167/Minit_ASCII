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
}

void Character::receiveDamage(int damage)
{
    life -= damage;
    if (checkIsDead())
    {
        // DeathEvent
    }
}

bool Character::checkIsDead() const
{
    return life <= 0;
}

void Character::update()
{
    Entity::update();
    move();
}

void Character::setDirection(int direction)
{
    this->direction = direction;
}

int Character::getDirection() const
{
    return direction;
}

