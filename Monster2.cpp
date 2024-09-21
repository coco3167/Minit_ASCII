#include "Monster2.h"

Monster2::Monster2(int x, int y):
    Character(x, y, Sprite("monster2.txt")){}

void Monster2::update(EntityManager& entity_manager)
{
    Character::update(entity_manager);
}


