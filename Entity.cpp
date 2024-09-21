#include "Entity.h"

Entity::Entity(int x, int y, int w, int h, Sprite sprite):
    hitbox{x,y,w,h},
    sprite{sprite}
{
}

Entity::Entity(int x, int y, Sprite sprite):
    Entity{x,y,sprite.getWidth(),sprite.getHeight(), sprite}
{
}

/*
====================
Getter
====================
*/
Vector2 Entity::getPosition() const { return {getHitbox().x,getHitbox().y}; }

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
    hitbox.x = position.x;
    hitbox.y = position.y;
}

void Entity::setHidden(bool hidden) { this->hidden = hidden; }







void Entity::update(EntityManager& entity_manager)
{
    //std::cout << "Entity::update()";
}