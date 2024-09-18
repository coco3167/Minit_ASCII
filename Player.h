#pragma once
#include "Character.h"

class Player : public Character
{
public:
    int getKey() const;
    void setKey(int key);
    void update() override;

private:
    int key = 0;
    
};
