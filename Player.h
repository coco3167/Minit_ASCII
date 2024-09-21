#pragma once
#include "Character.h"

class Player : public Character
{
public:
    using Character::Character;
    Player(int x, int y);

    Vector2 getSpawnPosition() const;
    void setSpawnPosition(Vector2 spawnPosition);
    int getKey() const;
    void addKey();
    void update(EntityManager& entity_manager) override;
    virtual void DeathEvent() override;
    void onInteract(Entity* interactor) override;

private:
    int key = 0;
    Vector2 spawnPosition;
};
