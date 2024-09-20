#include "WinSize.h"

#include <iostream>
#include <ostream>

WinSize* WinSize::instance = nullptr;

WinSize::WinSize(COORD size) : size(size){}

WinSize const* WinSize::getInstance(COORD const size)
{
    std::cout << "get instance : " << (instance==nullptr) << std::endl;
    if(instance==nullptr)
        instance = new WinSize(size);
    return instance;
}