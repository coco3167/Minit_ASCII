#pragma once
#include "InteractableEntity.h"

class Door : public InteractableEntity
{
public:
    void onInteract(Entity* interactor) override;
    void openDoor();

private:
    bool open = false;
};
