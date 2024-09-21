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

void Player::DeathEvent()
{
    Character::DeathEvent();
    setPosition({6,6});
}

void Player::onInteract(Entity* interactor)
{
    Character::onInteract(interactor);
    Character* character = dynamic_cast<Character*>(interactor);
    
    if(character != nullptr)
    {
        receiveDamage(character->getDamage());
    }
}

/*void Player::DeathEvent(EntityManager& entity_manager)
{
    Character::DeathEvent(entity_manager);
    setPosition({0, 0});
}*/
