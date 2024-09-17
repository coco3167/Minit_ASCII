#pragma once
#include "Entity.h"

class InteractableEntity : public Entity
{
public:
    virtual void onInteract(Entity* interactor) = 0;
    
};
