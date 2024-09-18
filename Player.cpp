#include "Player.h"
#include "Direction.h"

int Player::getKey() const
{
    return key;
}

void Player::setKey(int key)
{
    this->key = key;
}

void Player::update()
{
    Character::update();
}
