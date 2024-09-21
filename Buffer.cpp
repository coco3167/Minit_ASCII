#include "Buffer.h"

#include <iostream>

Buffer::Buffer()
{
    WinSize& win_size = WinSize::getInstance(); 
    
    //changer les width et height partout
    size = win_size.getSize();
    screenBuffer = std::vector<CHAR_INFO>(int(size.X*size.Y));
    coord = {0,0};
    writeRegion = SMALL_RECT{0, 0, SHORT(size.X - 1), SHORT(size.Y - 1)};
}

COORD Buffer::getSize() const
{
    return size;
}

COORD Buffer::getCoord() const
{
    return coord;
}

SMALL_RECT* Buffer::getWriteRegion()
{
    return &writeRegion;
}

std::vector<CHAR_INFO>& Buffer::getScreenBuffer()
{
    return screenBuffer;
}

CHAR_INFO * Buffer::getRawData()
{
    return screenBuffer.data();
}

CHAR_INFO& Buffer::at(int x, int y)
{
    if (x < 0) x = 0;
    if (x > size.X-1) x = size.X-1;
    if (y < 0) y = 0;
    if (y > size.Y-1) y = size.Y-1;
    return screenBuffer[y * size.X + x];
}
