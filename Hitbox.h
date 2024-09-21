#pragma once

struct Hitbox
{
    int x,y, w, h;
    bool isColliding(Hitbox other) const
    {
        if((other.x >= x + w)      //too far to the right
        || (other.x + other.w <= x)    // too far to the left
        || (other.y >= y + h)          // too far to the bottom
        || (other.y + other.h <= y))   // too far to the top
            return false; 
        return true; 
    }
};
