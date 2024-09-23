#include "WinSize.h"

#include <iostream>
#include <ostream>

WinSize* WinSize::instance = nullptr;

void WinSize::setSize(COORD size) { this->size = size; }

COORD const& WinSize::getSize() const { return size; }

WinSize::WinSize(COORD size) : size(size) {}

WinSize& WinSize::getInstance()
{
    if(instance==nullptr)
        instance = new WinSize({0,0});
    return *instance;
}