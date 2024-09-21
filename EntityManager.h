#pragma once
#include <unordered_set>
#include "Character.h"
#include "Player.h"


class EntityManager
{
private:
    
    Player* player;
    std::unordered_set<Entity*> entities;

public:
    Player* getPlayer() { return player; }
    void updateAll();
    void createEntity(std::string entityName, int x, int y);
    void addEntity(Entity* entity);
    void destroyEntity(Entity* entity);
    int willCollideVertical(Character* character,  int verticalSpeed) const;
    int willCollideHorizontal(Character* character, int horizontalSpeed) const;
};
