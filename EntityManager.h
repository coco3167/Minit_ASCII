#pragma once
#include <unordered_set>

#include "Character.h"
#include "Entity.h"

class EntityManager
{
private:
    std::unordered_set<Entity*> entities;

public:
    void updateAll();
    void addEntity(Entity* entity);
    void destroyEntity(Entity* entity);
    bool willCollide(Character* character) const;
    
};
