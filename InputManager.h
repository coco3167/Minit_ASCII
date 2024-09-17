#pragma once
#include <Windows.h>

#include "Player.h"

class InputManager
{    
private:
    Player const* player;
public:
    InputManager(Player const* player);
    void GetInput();
};
