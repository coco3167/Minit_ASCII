#include "InputManager.h"
#include <Windows.h>
#include <iostream>

int const Z = 0x5A;
int const S = 0x53;
int const Q = 0x51;
int const D = 0x44;

InputManager::InputManager(Player const* player)
{
    this->player = player;
}

void InputManager::GetInput()
{
    //Movement
    if(GetAsyncKeyState(VK_UP) || GetAsyncKeyState(Z))
        std::cout << "Up" << std::endl;

    if(GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(S))
        std::cout << "Down" << std::endl;
    
    if(GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(Q))
        std::cout << "Left" << std::endl;

    if(GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(D))
        std::cout << "Right" << std::endl;

    //Menuing
}
