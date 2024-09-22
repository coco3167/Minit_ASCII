#include "EntityManager.h"

#include <iostream>

#include "Direction.h"
#include "Door.h"
#include "Hitbox.h"
#include "InteractableEntity.h"
#include "Key.h"
#include "Monster1.h"
#include "Monster2.h"
#include "Player.h"
#include "Spawn.h"
#include "Teleporter.h"
#include "Wall.h"
#include "WinSize.h"

void EntityManager::updateAll()
{
    for (auto it = entities.begin() ; it != entities.end() ; it++)
    {
        if((*it)->shouldDestroy())
            it = entities.erase(it);
        else
            (*it)->update(*this);
    }
}

void EntityManager::resetEntities()
{
    for (auto it = entities.begin() ; it != entities.end() ; it++)
    {
        //(*it)->setPosition((*it)->getSpawnPosition());
        //(*it)->setHidden(false);
        //(*it)->setCollision((*it)->getStartCollision());
        (*it)->reset();
    }
}

void EntityManager::removeAllEntities() { entities.clear(); }

void EntityManager::createEntity(std::string entityName, int x, int y)
{
    if (entityName == "p")
    {
        Player* newPlayer = new Player(x, y);
        addEntity(newPlayer);
        if (player == nullptr)
        {
            player = newPlayer;
        }
    }
    else if (entityName == "k")
        addEntity(new Key(x, y));
    
    else if (entityName == "d")
        addEntity(new Door(x, y));
    
    else if (entityName == "m1")
        addEntity(new Monster1(x, y));
    
    else if (entityName == "m2")
        addEntity(new Monster2(x, y));
    
    else if (entityName == "s")
        addEntity(new Spawn(x, y));

    else if (entityName == "t")
    {
        Teleporter* newTeleporter = new Teleporter(x, y); 
        addEntity(newTeleporter);
        if (teleporter1 == nullptr)
            teleporter1 = newTeleporter;
        else if (teleporter2 == nullptr)
        {
            teleporter2 = newTeleporter;
            teleporter1->setOtherTeleporter(teleporter2);
            teleporter2->setOtherTeleporter(teleporter1);
        }
    }
}

void EntityManager::createWall(int x, int y, int w, int h)
{
    addEntity(new Wall(x, y, w, h));
}

void EntityManager::addEntity(Entity* entity)
{
    entities.insert(entity);
}

void EntityManager::destroyEntity(Entity* entity)
{
    entities.erase(entity);
    delete entity;
}

int EntityManager::willCollideVertical(Character* character, int verticalSpeed) const
{
    Vector2 characterActualPosition = character->getPosition();
    int dir = character->getDirection();

    // In which direction we would go vertically
    if ((dir & UP) == UP) { characterActualPosition.y -= verticalSpeed; }
    if ((dir & DOWN) == DOWN) { characterActualPosition.y += verticalSpeed; }

    // Depreciated, use of a moving camera instead
        // Test we don't exit box vertically
        // if (characterActualPosition.y < 0) { return 0; }
        // if (characterActualPosition.y + character->getHitbox().h > WinSize::getInstance().getSize().X) { return 0; }

    // Get Hitbox in place where we would like to be
    Hitbox hitbox = (character->getHitbox());
    hitbox.y = characterActualPosition.y;
    
    // test collision with others entity
    for (auto it = entities.begin(); it != entities.end(); it++)
    {
        Entity* entity = *it;
        if (entity != character && entity->getCollision() && hitbox.isColliding(entity->getHitbox()))
        {
            // Try interaction on colliding entity
            InteractableEntity* interactable = dynamic_cast<InteractableEntity*>(entity);
            if(interactable != nullptr)
            {
                interactable->onInteract(character);
            }
            // Collide 
            if (verticalSpeed > 1)
                return willCollideVertical(character, verticalSpeed - 1);
            return 0;
        }
    }
    // no collision detected
    return verticalSpeed;
}

int EntityManager::willCollideHorizontal(Character* character, int horizontalSpeed) const
{
    Vector2 characterActualPosition = character->getPosition();
    int dir = character->getDirection();

    // In which direction we would go
    if ((dir & LEFT) == LEFT) { characterActualPosition.x -= horizontalSpeed; }
    if ((dir & RIGHT) == RIGHT) { characterActualPosition.x += horizontalSpeed; }

    // Depreciated, use of a moving camera instead
        // Test we don't exit box
        // if (characterActualPosition.x < 0) { return false; }
        // if (characterActualPosition.x + character->getHitbox().w > WinSize::getInstance().getSize().X) { return false; }

    // Get Hitbox in place where we would like to be
    Hitbox hitbox = (character->getHitbox());
    hitbox.x = characterActualPosition.x;
    
    // test collision with others entity
    for (auto it = entities.begin(); it != entities.end(); it++)
    {
        Entity* entity = *it;
        if (entity != character && entity->getCollision() && hitbox.isColliding(entity->getHitbox()))
        {
            // Try interaction on colliding entity
            InteractableEntity* interactable = dynamic_cast<InteractableEntity*>(entity);
            if(interactable != nullptr)
            {
                interactable->onInteract(character);
            }
            // Collide
            if (horizontalSpeed > 1)
                return willCollideHorizontal(character, horizontalSpeed - 1);
            return 0;
        }
    }
    // no collision detected
    return horizontalSpeed;
}

