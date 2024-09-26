#include "Entity.h"

Entity::Entity(int x, int y, int w, int h, Sprite sprite):
    hitbox{x,y,w,h},
    sprite{sprite}
{
    setSpawnPosition({x, y});
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

bool Entity::getCollision() const { return collision; }

Sprite const& Entity::getSprite() const { return sprite; }

Vector2 Entity::getSpawnPosition() const { return spawnPosition; }

bool Entity::getStartCollision() const { return startCollision; }

Hitbox Entity::getHitbox() const { return hitbox; }

/*
====================
Setter
====================
*/
void Entity::setSprite(const Sprite& sprite) { this->sprite = sprite; }

void Entity::setPosition(const Vector2& position)
{
    hitbox.x = position.x;
    hitbox.y = position.y;
}

void Entity::setHidden(bool hidden) { this->hidden = hidden; }

void Entity::setHitbox(int x, int y, int w, int h) { hitbox = {x,y,w,h}; }

void Entity::setCollision(bool collision) { this->collision = collision; }

void Entity::setStartCollision(bool startCollision) { this->startCollision = startCollision; }

void Entity::setSpawnPosition(Vector2 spawnPosition) { this->spawnPosition = spawnPosition; }





void Entity::update(EntityManager& entity_manager) { }

void Entity::reset() { setPosition(getSpawnPosition()); }
