﻿#include "EntityManager.h"
#include "Direction.h"
#include "Hitbox.h"

void EntityManager::updateAll()
{
    for (auto it = entities.begin() ; it != entities.end() ; it++)
        (*it)->update(*this);
}

void EntityManager::addEntity(Entity* entity)
{
    entities.insert(std::unique_ptr<Entity>(entity));
}

void EntityManager::destroyEntity(Entity* entity)
{
    for (auto it = entities.begin(); it != entities.end(); it++)
        if ((*it).get() == entity)
            entities.erase(it);
}

bool EntityManager::willCollide(Character* character) const
{
    Vector2 characterActualPosition = character->getPosition();
    int dir = character->getDirection();
   
    if ((dir & LEFT) == LEFT) { characterActualPosition.x -= 1; }

    if ((dir & RIGHT) == RIGHT) { characterActualPosition.x += 1; }

    if ((dir & UP) == UP) { characterActualPosition.y -= 1; }

    if ((dir & DOWN) == DOWN) { characterActualPosition.y += 1; }

    Hitbox hitbox = (character->getHitbox());
    hitbox.x = characterActualPosition.x;
    hitbox.y = characterActualPosition.y;
    
    // test collision with others entity
    for (auto it = entities.begin(); it != entities.end(); it++)
    {
        if ((*it).get() != character)
            if (hitbox.isColliding((*it)->getHitbox()))
            {
                // Collide
                character->setDirection(0);
                return true;
            }
    }
    return false;
}
