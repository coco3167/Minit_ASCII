#pragma once
#include "windows.h"

// Width and height of the window in characters
// Is not exactly a Singleton
struct WinSize
{
public:
    // Singleton related deletion
    WinSize() = delete;
    WinSize(const WinSize&) = delete;
    void operator=(const WinSize&) = delete;

    const COORD size;
    
    static WinSize const* getInstance(COORD const size = {0, 0});

    
private:
    WinSize(COORD size);
    static WinSize* instance;
};

