#pragma once

#include <windows.h>
#include <vector>
#include "WinSize.h"

class Buffer
{
private:
	std::vector<CHAR_INFO> screenBuffer;
	COORD size;
	COORD coord;
	SMALL_RECT writeRegion;
public:
	Buffer();
	COORD getSize();
	COORD getCoord();
	SMALL_RECT* getWriteRegion();
	std::vector<CHAR_INFO>& getScreenBuffer();
	CHAR_INFO* getRawData();
};

