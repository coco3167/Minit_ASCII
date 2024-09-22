#include "Monster1.h"

#include <iostream>
#include <ostream>

#include "Direction.h"
#include "Player.h"

Monster1::Monster1(int x, int y): Character(x, y, Sprite("monster1_left.txt"))
{
    setDamage(1);
    setSpriteLeft(Sprite("monster1_left.txt"));
    setSpriteRight(Sprite("monster1_right.txt"));
    setSpriteDown(Sprite("monster1_left.txt"));
    setSpriteUp(Sprite("monster1_right.txt"));
}

void Monster1::update(EntityManager& entity_manager)
{
    Character::update(entity_manager);
    setRandomDirection();
}

void Monster1::onInteract(Entity* interactor)
{
    Character::onInteract(interactor);
    Player* player = dynamic_cast<Player*>(interactor);
    
    if(player != nullptr)
    {
        player->receiveDamage(getDamage());
    }
}

void Monster1::reset()
{
    Character::reset();
    setLife(1);
    setDamage(1);
    setVerticalSpeed(1);
    setHorizontalSpeed(2);
}

void Monster1::setRandomDirection()
{
    std::vector<int> list = {LEFT, RIGHT, UP, DOWN};
    // OPTION 1 : good pattern BUT all monsters have same
    std::srand(std::time(0));
    setDirection(list[std::rand() % 4]);
}


