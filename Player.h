#pragma once
#include "Character.h"

class Player : public Character
{
public:
    Player(int x, int y, int w, int h, Sprite sprite);
    Player(int x, int y, int w, int h);
    int getKey() const;
    void setKey(int key);
    void update(EntityManager const& entity_manager) override;

private:
    int key = 0;
    
};
