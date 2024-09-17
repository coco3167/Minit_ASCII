#include "Player.h"
#include "Direction.h"

int Player::getKey()
{
    return key;
}

void Player::setKey(int key)
{
    this->key = key;
}

void Player::move(int direction)
{
    if (canMove(direction))
    {
        
    }
}

bool Player::canMove(int direction)
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
}

void Player::attack(int damage)
{
}
