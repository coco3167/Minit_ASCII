#include "Spawn.h"

Spawn::Spawn(int x, int y) : Entity(x, y, Sprite("spawn.txt"))
{
    setCollision(false);
    setStartCollision(false);
}
