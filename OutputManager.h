#pragma once

#include <unordered_set>

#include "Buffer.h"
#include "WinSize.h"
#include "Player.h"


class OutputManager
{

public:
    OutputManager(Player& player, int const fontSize = 0);

    Player& player;
    
    void clearBuffer();
    void drawBuffer();
    void maximizeConsoleWindow(int const fontSize);
    void setConsoleStyle();
    void setFixedConsoleSize(SHORT width, SHORT height);
    void displayEntities(std::unordered_set<Entity*> entities);

private:
    Buffer buffer;
    DWORD setFont(int const fontSize = 12);
    COORD size;
};
