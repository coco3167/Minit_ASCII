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

    
    static WinSize& getInstance();

    void setSize(COORD size);
    COORD const& getSize();

    
private:
    COORD size;
    WinSize(COORD size);
    static WinSize* instance;
};

