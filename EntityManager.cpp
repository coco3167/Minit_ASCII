#include "EntityManager.h"

void EntityManager::updateAll()
{
    for (Entity* entity : entities)
        entity->update();
}

void EntityManager::addEntity(Entity* entity)
{
    entities.insert(entity);
}

void EntityManager::destroyEntity(Entity* entity)
{
    entities.erase(entity);
}
