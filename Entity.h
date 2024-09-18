#pragma once
#include <string>
#include <vector>

#include "Vector2.h"
#include "Hitbox.h"

class EntityManager;

typedef std::vector<std::wstring> Sprite;

class Entity
{
public:
    Entity(int x, int y, int w, int h, Sprite sprite);
    // Getter
    Vector2 getPosition() const;
    bool isHidden() const;
    Sprite getSprite() const;
    virtual void update(EntityManager const& entity_manager);
    Hitbox getHitbox() const;

    // Setter
    void setSprite(const Sprite& sprite);
    void setPosition(const Vector2& position);
    void setHidden(bool hidden);
    
private:
    Vector2 position;
    bool hidden;
    Sprite sprite;
    Hitbox hitbox;
};
