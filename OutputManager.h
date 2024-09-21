#pragma once

#include <memory>
#include <unordered_set>

#include "Buffer.h"
#include "EntityManager.h"
#include "WinSize.h"
#include "Player.h"


class OutputManager
{
private:
    Buffer buffer;
    DWORD setFont(int const fontSize = 12);
    COORD size;
    
public:
    Player& player;

public:
    OutputManager(Player& player, int const fontSize = 0);
    void clearBuffer();
    void drawBuffer();
    void maximizeConsoleWindow(int const fontSize);
    void setConsoleStyle();
    void setFixedConsoleSize(SHORT width, SHORT height);
    void display(Entity const& entity);
};
