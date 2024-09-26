#pragma once

#include "Player.h"

class InputManager
{        
public:
    InputManager(Player& player);
    void getInput() const;

private:
    Player& player;
};
