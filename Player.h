#pragma once
#include "Character.h"

class Player : public Character
{
public:
    using Character::Character;
    Player(int x, int y);
    int getKey() const;
    void setKey(int key);
    
    void update(EntityManager const& entity_manager) override;
    void DeathEvent(EntityManager const& entity_manager) override;

private:
    int key = 0;
    bool dead = false;
};
