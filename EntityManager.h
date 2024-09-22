﻿#pragma once
#include <unordered_set>
#include "Character.h"
#include "Player.h"
#include "Teleporter.h"


class EntityManager
{
public:
    Player* getPlayer() { return player; }
    void updateAll();
    void resetEntities();
    void removeAllEntities();
    void createEntity(std::string entityName, int x, int y);
    void createWall(int x, int y, int w, int h);
    void addEntity(Entity* entity);
    void destroyEntity(Entity* entity);
    int willCollideVertical(Character* character,  int verticalSpeed) const;
    int willCollideHorizontal(Character* character, int horizontalSpeed) const;
    std::unordered_set<Entity*> getEntities() { return entities; }

private:
    Player* player;
    Teleporter* teleporter1;
    Teleporter* teleporter2;
    std::unordered_set<Entity*> entities;
};
