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
        setPosition({getPosition().x , getPosition().y - moveVerticalSpeed});

    if ((direction & DOWN) == DOWN)
        setPosition({getPosition().x , getPosition().y + moveVerticalSpeed});
}

void Character::moveHorizontal(int moveHorizontalSpeed)
{
    if ((direction & LEFT) == LEFT)
        setPosition({getPosition().x - moveHorizontalSpeed, getPosition().y});
    
    if ((direction & RIGHT) == RIGHT)    
        setPosition({getPosition().x + moveHorizontalSpeed, getPosition().y});
}

void Character::receiveDamage(int damage)
{
    life -= damage;
    //if (checkIsDead())
    //{
    //    DeathEvent();
    //}
}

void Character::setVerticalSpeed(int verticalSpeed) { this->verticalSpeed = verticalSpeed; }

void Character::setHorizontalSpeed(int horizontalSpeed) { this->horizontalSpeed = horizontalSpeed; }

void Character::setLife(int life) { this->life = life; }

bool Character::checkIsDead() const { return life <= 0; }

int Character::getDamage() const { return damage; }

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
