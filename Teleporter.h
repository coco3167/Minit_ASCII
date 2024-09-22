#pragma once
#include "InteractableEntity.h"

class Teleporter : public InteractableEntity
{
public:
    Teleporter(int x, int y);
    
    void onInteract(Entity* interactor) override;
    Teleporter* getOtherTeleporter();
    void setOtherTeleporter(Teleporter* other);

private:
    Teleporter* otherTeleporter;
};
