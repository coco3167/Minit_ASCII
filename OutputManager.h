#pragma once

#include "Buffer.h"
#include "Player.h"


class OutputManager
{
private:
    Buffer buffer;
    Player& player;
public:
    OutputManager(Player& player);
    void clearBuffer();
    void drawBuffer();
    void maximizeConsoleWindow();
    void setConsoleStyle();
    void setFixedConsoleSize(SHORT width, SHORT height);
    void display(Entity const& entity);
};
