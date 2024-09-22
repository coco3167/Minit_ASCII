#pragma once
#include <random>

#include "Character.h"
#include "NYTimer.h"

class Monster2 : public Character
{
public:
    using Character::Character;
    Monster2(int x, int y);

    void setRandomDirection();
    
    void update(EntityManager& entity_manager) override;
    void onInteract(Entity* interactor) override;
    void reset() override;
    
private:
    std::mt19937 generator;
    NYTimer timer;
    float delayChangeDirection = 1.f;
};
