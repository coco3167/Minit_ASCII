﻿#pragma once
#include <string>
#include <vector>
#include "Vector2.h"


class Entity
{

public:
    // Getter
    Vector2 getPosition() const;
    bool isHidden() const;
    std::vector<std::string> getSprite() const;

    // Setter
    void setSprite(const std::vector<std::string>& sprite);
    void setPosition(const Vector2& Position);
    void setHidden(bool hidden);
    
private:
    Vector2 Position;
    bool hidden;
    std::vector<std::string> sprite;
    
};
