#include "Player.h"

#include "Spawn.h"

Player::Player(int x, int y): Character(x, y, Sprite("player.txt")) { setSpawnPosition({x, y}); }

int Player::getKey() const { return key; }

void Player::setKey(int key) { this->key = key; }

void Player::addKey() { this->key++; }

void Player::update(EntityManager& entity_manager)
{
    Character::update(entity_manager);
}

void Player::reset()
{
    Character::reset();
    setLife(1);
    setKey(0);
    setDamage(0);
    setVerticalSpeed(2);
    setHorizontalSpeed(2);
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