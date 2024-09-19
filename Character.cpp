#include "Character.h"
#include "EntityManager.h"

#include <iostream>

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
void Character::setDirection(int direction) { this->direction = direction; }






void Character::moveVertical(int moveVerticalSpeed)
{
    if(direction == 0)
        return;
    
    if ((direction & UP) == UP)
        setPosition({getPosition().x , getPosition().y - moveVerticalSpeed});

    if ((direction & DOWN) == DOWN)
        setPosition({getPosition().x , getPosition().y + moveVerticalSpeed});
}

void Character::moveHorizontal(int moveHorizontalSpeed)
{
    if(direction == 0)
        return;
    
    if ((direction & LEFT) == LEFT)
        setPosition({getPosition().x - moveHorizontalSpeed, getPosition().y});
    
    if ((direction & RIGHT) == RIGHT)    
        setPosition({getPosition().x + moveHorizontalSpeed, getPosition().y});
}

void Character::receiveDamage(int damage)
{
    life -= damage;
    if (checkIsDead())
    {
        // DeathEvent
    }
}

bool Character::checkIsDead() const { return life <= 0; }

void Character::update(EntityManager const& entity_manager)
{
    Entity::update(entity_manager);
    
    int moveHorizontalSpeed = entity_manager.willCollideHorizontal(this, getHorizontalSpeed());
    if (moveHorizontalSpeed > 0)
        moveHorizontal(moveHorizontalSpeed);
    
    int moveVerticalSpeed = entity_manager.willCollideVertical(this, getVerticalSpeed());
    if (moveVerticalSpeed > 0)
        moveVertical(moveVerticalSpeed);
}

void Character::DeathEvent(EntityManager const& entity_manager)
{
}
