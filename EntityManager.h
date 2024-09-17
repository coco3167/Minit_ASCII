#pragma once
#include <unordered_set>

#include "Entity.h"

class EntityManager
{
private:
    std::unordered_set<Entity*> entities;

public:
    void updateAll();
    void addEntity(Entity* entity);
    void destroyEntity(Entity* entity);
    
};
