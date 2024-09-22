#include "Monster2.h"

#include "Direction.h"
#include "Player.h"

Monster2::Monster2(int x, int y):
    Character(x, y, Sprite("monster2_left.txt"))
{
    setDamage(1);
    timer.start();
    setSpriteLeft(Sprite("monster2_left.txt"));
    setSpriteRight(Sprite("monster2_right.txt"));
    setSpriteDown(Sprite("monster2_left.txt"));
    setSpriteUp(Sprite("monster2_right.txt"));
}

void Monster2::update(EntityManager& entity_manager)
{
    Character::update(entity_manager);
    if (timer.getElapsedSeconds(false) >= delayChangeDirection)
    {
        setRandomDirection();
        timer.restart();
    }
}

void Monster2::onInteract(Entity* interactor)
{
    Character::onInteract(interactor);
    Player* player = dynamic_cast<Player*>(interactor);
    
    if(player != nullptr)
    {
        player->receiveDamage(getDamage());
    }
}

void Monster2::reset()
{
    Character::reset();
    setLife(1);
    setDamage(1);
    setVerticalSpeed(1);
    setHorizontalSpeed(2);
}

void Monster2::setRandomDirection()
{
    std::vector<int> list = {LEFT, RIGHT, UP, DOWN};
    
    std::uniform_int_distribution<> distr(0, list.size() - 1);
    setDirection(list[distr(generator)]);
}

