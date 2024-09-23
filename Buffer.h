#pragma once

#include <windows.h>
#include <vector>


class Buffer
{
public:
	Buffer();

	// const getter
	COORD getSize() const;
	COORD getCoord() const;

	// non-const getter
	SMALL_RECT* getWriteRegion();
	std::vector<CHAR_INFO>& getScreenBuffer();
	CHAR_INFO* getRawData();
	
	CHAR_INFO& at(int x, int y);

private:
	std::vector<CHAR_INFO> screenBuffer;
	COORD size;
	COORD coord;
	SMALL_RECT writeRegion;
};

