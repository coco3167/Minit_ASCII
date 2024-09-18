#include "Player.h"
#include "Direction.h"


Player::Player(int x, int y, int w, int h):
    Character(x,y,w,h,
    {
        { 0x2588, 0x2588, 0x2588, 0x2588, 0x2588 },
        { 0x2588, 0x2588, 0x2588, 0x2588, 0x2588 },
        { 0x2588, 0x2588, 0x2588, 0x2588, 0x2588 },
        { 0x2588, 0x2588, 0x2588, 0x2588, 0x2588 },
        { 0x2588, 0x2588, 0x2588, 0x2588, 0x2588 }
    })
{}

int Player::getKey() const
{
    return key;
}

void Player::setKey(int key)
{
    this->key = key;
}

void Player::update(EntityManager const& entity_manager)
{
    Character::update(entity_manager);
}
