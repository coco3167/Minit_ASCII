#pragma once

#include <iostream>
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
    void setFixedConsoleSize(int width, int height);

    void display(Entity const& entity);
};
