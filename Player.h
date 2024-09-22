#pragma once
#include "Character.h"

class Player : public Character
{
public:
    using Character::Character;
    Player(int x, int y);
    
    int getKey() const;
    void setKey(int key);
    void addKey();
    
    void update(EntityManager& entity_manager) override;
    void reset() override;
    void onInteract(Entity* interactor) override;

private:
    int key = 0;
    
};
