#pragma once

#include "Player.h"

class InputManager
{    
private:
    Player* player;
    
public:
    InputManager(Player* player);
    void getInput() const;
};
