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

/*
====================
Setter
====================
*/
void Character::setDirection(int direction) { this->direction = direction; }






void Character::move()
{
    if(direction == 0)
        return;
    
    if ((direction & LEFT) == LEFT)
    {
        setPosition({getPosition().x - 1, getPosition().y});
    }

    if ((direction & RIGHT) == RIGHT)
    {
        setPosition({getPosition().x + 1, getPosition().y});
    }

    if ((direction & UP) == UP)
    {
        setPosition({getPosition().x , getPosition().y - 1});
    }

    if ((direction & DOWN) == DOWN)
    {
        setPosition({getPosition().x , getPosition().y + 1});
    }
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
    if (! entity_manager.willCollide(this))
        move();
}