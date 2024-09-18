#include "Player.h"
#include "Direction.h"


Player::Player(int x, int y, int w, int h, Sprite sprite)
{
    setSprite(sprite);
    setPosition({x, y});
    
}

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
