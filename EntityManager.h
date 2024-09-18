#pragma once
#include <unordered_set>
#include <memory>

#include "Character.h"

class EntityManager
{
private:
    std::unordered_set<std::unique_ptr<Entity>> entities;

public:
    void updateAll();
    void addEntity(Entity* entity);
    void destroyEntity(Entity* entity);
    bool willCollide(Character* character) const;
    
};
