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
    Hitbox getHitbox() const;
    bool isHidden() const;
    const Sprite& getSprite() const;

    // Setter
    void setSprite(const Sprite& sprite);
    void setPosition(const Vector2& position);
    void setHidden(bool hidden);
    void setHitbox(int x, int y, int w, int h);
    
    virtual void update(EntityManager const& entity_manager);
    
private:
    bool hidden;
    Sprite sprite;
    Hitbox hitbox;
};
