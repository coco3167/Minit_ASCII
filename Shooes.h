#pragma once
#include "InteractableEntity.h"

class Shooes : public InteractableEntity
{
public:
    Shooes(int x, int y);
    void onInteract(Entity* interactor) override;
};
