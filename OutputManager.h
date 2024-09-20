#pragma once

#include "Buffer.h"
#include "Entity.h"
#include "WinSize.h"


class OutputManager
{
private:
    Buffer buffer;
    DWORD setFont(int fontSize = 12);
    COORD size;
    
public:
    OutputManager();
    void clearBuffer();
    void drawBuffer();
    void maximizeConsoleWindow();
    void setFixedConsoleSize(SHORT width, SHORT height);
    void display(Entity const& entity);
};
