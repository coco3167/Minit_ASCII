#include "Character.h"

#include <iostream>

#include "EntityManager.h"

#include "Direction.h"

/*
====================
Getter
====================
*/
int Character::getLife() const { return life; }

int Character::getDirection() const { return direction; }

int Character::getHorizontalSpeed() const { return horizontalSpeed; }

int Character::getVerticalSpeed() const { return verticalSpeed; }

/*
====================
Setter
====================
*/
// Set the direction the character would like to go
void Character::setDirection(int newDirection) { direction = newDirection; }

void Character::setDamage(int damage) { this->damage = damage; }

void Character::moveVertical(int moveVerticalSpeed)
{
    if ((direction & UP) == UP)
    {
        setPosition({getPosition().x , getPosition().y - moveVerticalSpeed});
        setSprite(getUpSprite());
    }
    if ((direction & DOWN) == DOWN)
    {
        setPosition({getPosition().x , getPosition().y + moveVerticalSpeed});
        setSprite(getDownSprite());
    }
        
}

void Character::moveHorizontal(int moveHorizontalSpeed)
{
    if ((direction & LEFT) == LEFT)
    {
        setPosition({getPosition().x - moveHorizontalSpeed, getPosition().y});
        setSprite(leftSprite);
    }
    if ((direction & RIGHT) == RIGHT)
    {
        setPosition({getPosition().x + moveHorizontalSpeed, getPosition().y});
        setSprite(rightSprite);
    }
}

void Character::receiveDamage(int damage) { life -= damage; }

void Character::setVerticalSpeed(int verticalSpeed) { this->verticalSpeed = verticalSpeed; }

void Character::setHorizontalSpeed(int horizontalSpeed) { this->horizontalSpeed = horizontalSpeed; }

void Character::setLife(int life) { this->life = life; }

void Character::setSpriteRight(Sprite sprite) { rightSprite = sprite; }

void Character::setSpriteLeft(Sprite sprite) { leftSprite = sprite; }

void Character::setSpriteUp(Sprite sprite) { upSprite = sprite; }

void Character::setSpriteDown(Sprite sprite) { downSprite = sprite; }

bool Character::checkIsDead() const { return life <= 0; }

int Character::getDamage() const { return damage; }

Sprite Character::getLeftSprite() const { return leftSprite; }

Sprite Character::getRightSprite() const { return rightSprite; }

Sprite Character::getUpSprite() const { return upSprite; }

Sprite Character::getDownSprite() const { return downSprite; }

void Character::update(EntityManager& entity_manager)
{
    Entity::update(entity_manager);

    if(direction == 0)
        return;
    
    int moveHorizontalSpeed = entity_manager.willCollideHorizontal(this, getHorizontalSpeed());
    if (moveHorizontalSpeed > 0)
        moveHorizontal(moveHorizontalSpeed);
    
    int moveVerticalSpeed = entity_manager.willCollideVertical(this, getVerticalSpeed());
    if (moveVerticalSpeed > 0)
        moveVertical(moveVerticalSpeed);
}

void Character::onInteract(Entity* interactor)
{
}

void Character::reset()
{
    InteractableEntity::reset();
    setHidden(false);
    setCollision(true);
}
