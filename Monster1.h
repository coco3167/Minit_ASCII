#pragma once

#include "Character.h"

class Monster1 : public Character
{
public:
    using Character::Character;
    Monster1(int x, int y);

    void setRandomDirection();
    void update(EntityManager& entity_manager) override;
    void onInteract(Entity* interactor) override;
    void reset() override;
};
