#pragma once
#include "InteractableEntity.h"

class Key : public InteractableEntity
{
public:
    void onInteract(Entity* interactor) override;
};
