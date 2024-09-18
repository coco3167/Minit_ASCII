#include "Entity.h"
#include "EntityManager.h"

#include <iostream>
#include <ostream>

/*
====================
Getter
====================
*/

Entity::Entity(int x, int y, int w, int h, Sprite sprite):
    hitbox{x,y,w,h},
    sprite{sprite}
{
}

Vector2 Entity::getPosition() const
{
    return position;
}

bool Entity::isHidden() const
{
    return hidden;
}

Sprite Entity::getSprite() const
{
    return sprite;
}

void Entity::update(EntityManager const& entity_manager)
{
    //std::cout << "Entity::update()";
}

Hitbox Entity::getHitbox() const
{
    return hitbox;
}

/*
====================
Setter
====================
*/

void Entity::setSprite(const Sprite& sprite)
{
    this->sprite = sprite;
}

void Entity::setPosition(const Vector2& position)
{
    this->position = position;
}

void Entity::setHidden(bool hidden)
{
    this->hidden = hidden;
}
