#pragma once
#include "Entity.h"

class InteractableEntity : public Entity
{
public:
    using Entity::Entity;
    
    InteractableEntity(int x, int y, Sprite sprite);
    virtual void onInteract(Entity* interactor) = 0;
    
};
