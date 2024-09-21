#pragma once
#include "InteractableEntity.h"

class Key : public InteractableEntity
{
public:
    Key(int x, int y);
    void onInteract(Entity* interactor) override;
    void update(EntityManager& entity_manager) override;
};
