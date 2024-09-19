#pragma once
#include "Vector2.h"

struct Hitbox
{
    int x,y, w, h;
    bool isColliding(Hitbox other) const
    {
        if((other.x >= x + w)      // trop à droite
        || (other.x + other.w <= x)    // trop à gauche
        || (other.y >= y + h)          // trop en bas
        || (other.y + other.h <= y))   // trop en haut
            return false; 
        return true; 
    }
};
