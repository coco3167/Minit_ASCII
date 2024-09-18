#include "Player.h"

Player::Player(int x, int y):
    Character(x,y,5,5,
    {
        { 0x254B, 0x2588, 0x2588, 0x2588, 0x254B },
        { 0x2588, 0x2588, 0x2588, 0x2588, 0x2588 },
        { 0x2588, 0x2588, 0x2588, 0x2588, 0x2588 },
        { 0x2588, 0x2588, 0x2588, 0x2588, 0x2588 },
        { 0x254B, 0x2588, 0x2588, 0x2588, 0x254B }
    })
{}

int Player::getKey() const
{
    return key;
}

void Player::setKey(int newKey)
{
    this->key = newKey;
}

void Player::update(EntityManager const& entity_manager)
{
    Character::update(entity_manager);
    if (dead)
        DeathEvent(entity_manager);
}

void Player::DeathEvent(EntityManager const& entity_manager)
{
    Character::DeathEvent(entity_manager);
    setPosition({0, 0});
}
