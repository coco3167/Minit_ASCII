#include "Buffer.h"

Buffer::Buffer():
    screenBuffer(WIDTH*HEIGHT)
{
    size = {WIDTH, HEIGHT};
    coord = {0, 0};
    writeRegion = {0, 0, WIDTH - 1, HEIGHT - 1};
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
    if (x > WIDTH-1) x = WIDTH-1;
    if (y < 0) y = 0;
    if (y > HEIGHT-1) y = HEIGHT-1;
    return screenBuffer[y * WIDTH + x];
}
