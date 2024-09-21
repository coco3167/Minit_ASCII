#pragma once
#include <random>

#include "Character.h"

class Monster2 : public Character
{
public:
    using Character::Character;
    Monster2(int x, int y);
    
    void update(EntityManager& entity_manager) override;
    void setRandomDirection();
    
private:
    std::mt19937 generator;
};
