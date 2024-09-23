#pragma once
#include <unordered_set>
#include "Player.h"
#include "Teleporter.h"
#include "EndFlag.h"


class EntityManager
{
public:
    ~EntityManager();
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
    bool loop();
    std::unordered_set<Entity*> getEntities() { return entities; }

private:
    Player* player = nullptr;
    Teleporter* teleporter1 = nullptr;
    Teleporter* teleporter2 = nullptr;
    EndFlag* endFlag = nullptr;
    std::unordered_set<Entity*> entities;
};
