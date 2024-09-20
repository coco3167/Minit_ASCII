#pragma once
#include <unordered_set>
#include <memory>

#include "Character.h"
#include "WinSize.h"

class EntityManager
{
private:
    std::unordered_set<std::unique_ptr<Entity>> entities;

public:
    void updateAll();
    void addEntity(Entity const& entity);
    void destroyEntity(Entity* entity);
    int willCollideVertical(Character* character,  int verticalSpeed) const;
    int willCollideHorizontal(Character* character, int horizontalSpeed) const;
    
};
