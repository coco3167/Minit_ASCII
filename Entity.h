#pragma once

#include "Vector2.h"
#include "Hitbox.h"
#include "Sprite.h"

class EntityManager;

/// <summary>
/// This class represent every single thing in the game that has a sprite and a hitbox.
/// </summary>
class Entity
{
public:
    Entity(int x, int y, int w, int h, Sprite sprite);
    Entity(int x, int y, Sprite sprite);
    
    // Getter
    Vector2 getPosition() const;
    Hitbox getHitbox() const;
    bool isHidden() const;
    bool shouldDestroy() const;
    Sprite const& getSprite() const;

    // Setter
    void setSprite(const Sprite& sprite);
    void setPosition(const Vector2& position);
    void setHidden(bool hidden);
    void setHitbox(int x, int y, int w, int h);
    
    virtual void update(EntityManager& entity_manager);
    
private:
    bool hidden = false;
    Sprite sprite;
    Hitbox hitbox;

protected:
    bool destroy = false;
};
