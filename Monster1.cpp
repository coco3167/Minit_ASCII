#include "Monster1.h"

#include <iostream>
#include <ostream>

#include "Direction.h"
#include "Player.h"

Monster1::Monster1(int x, int y):
    Character(x, y, Sprite("monster1.txt")){ setDamage(1); }

void Monster1::update(EntityManager& entity_manager)
{
    Character::update(entity_manager);
    setRandomDirection();
}

void Monster1::onInteract(Entity* interactor)
{
    Character::onInteract(interactor);
    std::cout << "Monster1::onInteract" << std::endl;
    Player* player = dynamic_cast<Player*>(interactor);
    
    if(player != nullptr)
    {
        player->receiveDamage(getDamage());
    }
}

void Monster1::setRandomDirection()
{
    std::vector<int> list = {LEFT, RIGHT, UP, DOWN};
    std::srand(std::time(0));
    setDirection(list[std::rand() % 4]);
    std::cout << "Monster1::setRandomDirection : " << getDirection() << std::endl;
}


