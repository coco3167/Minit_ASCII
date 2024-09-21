#include "Monster2.h"

#include "Direction.h"

Monster2::Monster2(int x, int y):
    Character(x, y, Sprite("monster2.txt")){}

void Monster2::update(EntityManager& entity_manager)
{
    Character::update(entity_manager);
    setRandomDirection();
}

void Monster2::setRandomDirection()
{
    std::vector<int> list = {LEFT, RIGHT, UP, DOWN};
    
    std::uniform_int_distribution<> distr(0, list.size() - 1);
    setDirection(list[distr(generator)]);
}

