#include "Entity.h"
#include "EntityManager.h"

#include <iostream>
#include <ostream>

Entity::Entity(int x, int y, int w, int h, Sprite sprite):
    hitbox{x,y,w,h},
    sprite{sprite}
{
}

/*
====================
Getter
====================
*/
Vector2 const& Entity::getPosition() const { return {getHitbox().x,getHitbox().y}; }

bool Entity::isHidden() const { return hidden; }

Sprite const& Entity::getSprite() const { return sprite; }

Hitbox Entity::getHitbox() const { return hitbox; }

void Entity::setHitbox(int x, int y, int w, int h) { hitbox = {x,y,w,h}; }

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
    setHitbox(position.x, position.y, getHitbox().w, getHitbox().h);
}

void Entity::setHidden(bool hidden) { this->hidden = hidden; }







void Entity::update(EntityManager const& entity_manager)
{
    //std::cout << "Entity::update()";
}