#pragma once
#include <string>
#include <vector>
#include "Vector2.h"

typedef std::vector<std::string> Sprite;

class Entity
{
public:
    Entity(int x, int y, int w, int h, Sprite sprite);
    // Getter
    Vector2 getPosition() const;
    bool isHidden() const;
    Sprite getSprite() const;
    virtual void update();

    // Setter
    void setSprite(const Sprite& sprite);
    void setPosition(const Vector2& position);
    void setHidden(bool hidden);
    
private:
    Vector2 position;
    bool hidden;
    Sprite sprite;
    
};
