#include "EntityManager.h"

#include "Direction.h"
#include "Hitbox.h"

void EntityManager::updateAll()
{
    for (Entity* entity : entities)
        entity->update(*this);
}

void EntityManager::addEntity(Entity* entity)
{
    entities.insert(entity);
}

void EntityManager::destroyEntity(Entity* entity)
{
    entities.erase(entity);
}

bool EntityManager::willCollide(Character* character) const
{
    Vector2 characterActualPosition = character->getPosition();
    int dir = character->getDirection();
   
    if (dir == LEFT)
    {
        //want to move left
        characterActualPosition.x -= 1;
    }

    if (dir == RIGHT)
    {
        //want to move right
        characterActualPosition.x += 1;
    }

    if (dir == UP)
    {
        //want to move up
        characterActualPosition.y -= 1;
    }

    if (dir == DOWN)
    {
        //want to move down
        characterActualPosition.y += 1;
    }

    // test collision with others entity
    for (Entity* entity : entities)
    {
        if (entity != character)
        {
            if (character->getHitbox().isColliding(entity->getHitbox()))
            {
                // Collide
                character->setDirection(0);
                return true;
            }
        }
    }
    return false;
}
