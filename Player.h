#pragma once
#include "Character.h"

class Player : public Character
{
public:
    using Character::Character;
    Player(int x, int y);
    int getKey() const;
    void addKey();
    
    void update(EntityManager& entity_manager) override;
    virtual void DeathEvent() override;

private:
    int key = 0;
};
