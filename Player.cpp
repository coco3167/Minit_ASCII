#include "Player.h"

Player::Player(int x, int y):
    Character(x, y, Sprite("player.txt"))
{}

int Player::getKey() const
{
    return key;
}

void Player::addKey()
{
    this->key++;
}

void Player::update(EntityManager& entity_manager)
{
    Character::update(entity_manager);
    /*if (dead)
        DeathEvent(entity_manager);*/
}

/*void Player::DeathEvent(EntityManager& entity_manager)
{
    Character::DeathEvent(entity_manager);
    setPosition({0, 0});
}*/
