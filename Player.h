#pragma once
#include "Character.h"

class Player : public Character
{
public:
    int getKey();
    void setKey(int key);

private:
    int key = 0;
    
    void move(int direction) override;
    bool canMove(int direction) override;
    void attack(int damage) override;
};
