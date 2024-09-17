#pragma once
#include "Character.h"

class Player : public Character
{
public:
    int getKey() const;
    void setKey(int key);

private:
    int key = 0;
    
};
