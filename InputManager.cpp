#include "InputManager.h"
#include <Windows.h>
#include <iostream>

#include "Direction.h"

// Keyboard hex adress
int const Z = 0x5A;
int const S = 0x53;
int const Q = 0x51;
int const D = 0x44;

InputManager::InputManager(Player* player)
{
    this->player = player;
}

void InputManager::getInput()
{
    int movement = 0;
    
    //Movement
    if(GetAsyncKeyState(VK_UP) || GetAsyncKeyState(Z))
    {
        movement |= UP;
    }

    if(GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(S))
    {
        movement |= DOWN;
    }
    
    if(GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(Q))
    {
        movement |= LEFT;
    }

    if(GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(D))
    {
        movement |= RIGHT;
    }

    if(movement != 0)
    {
        player->move(movement);
    }
        
    //Menuing
    if(GetAsyncKeyState(VK_ESCAPE))
    {
        exit(0);
    }
}
