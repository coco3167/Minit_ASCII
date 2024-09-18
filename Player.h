#pragma once
#include "Character.h"

class Player : public Character
{
public:
    using Character::Character;
    Player(int x, int y, int w, int h);
    int getKey() const;
    void setKey(int key);
    void update(EntityManager const& entity_manager) override;

private:
    int key = 0;
    
    
};
