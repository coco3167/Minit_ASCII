#pragma once

#include "Buffer.h"
#include "Entity.h"


class OutputManager
{
private:
    Buffer buffer;
public:
    void clearBuffer();
    void drawBuffer();
    void maximizeConsoleWindow();
    void setConsoleStyle();
    void setFixedConsoleSize(SHORT width, SHORT height);
    void display(Entity const& entity);
};
