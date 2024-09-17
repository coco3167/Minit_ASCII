#include "EntityManager.h"

void EntityManager::updateAll()
{
    std::unordered_set<Entity*>::iterator iterator = entities.begin();
    std::unordered_set<Entity*>::iterator const iterator_end = entities.end();

    while (iterator != iterator_end)
    {
        (*iterator)->update();
    }
}

void EntityManager::addEntity(Entity* entity)
{
    entities.insert(entity);
}

void EntityManager::destroyEntity(Entity* entity)
{
    entities.erase(entity);
}
