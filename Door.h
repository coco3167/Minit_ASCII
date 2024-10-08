﻿#pragma once
#include "InteractableEntity.h"

class Door : public InteractableEntity
{
public:
    Door(int x, int y);
    
    void openDoor();
    void onInteract(Entity* interactor) override;
    void reset() override;

private:
    bool open = false;
};
