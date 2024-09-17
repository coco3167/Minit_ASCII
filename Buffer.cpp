#include "Buffer.h"

Buffer::Buffer():
    screenBuffer(WIDTH*HEIGHT)
{
    size = {WIDTH, HEIGHT};
    coord = {0, 0};
    writeRegion = {0, 0, WIDTH - 1, HEIGHT - 1};
}

COORD Buffer::getSize()
{
    return size;
}

COORD Buffer::getCoord()
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
