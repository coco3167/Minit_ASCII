#include "EntityManager.h"

#include <iostream>

#include "Direction.h"
#include "Door.h"
#include "Hitbox.h"
#include "InteractableEntity.h"
#include "Key.h"
#include "Player.h"
#include "WinSize.h"

void EntityManager::updateAll()
{
    for (auto it = entities.begin() ; it != entities.end() ; it++)
        (*it)->update(*this);
}

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
    {
        Key* newKey = new Key(x, y);
        addEntity(newKey);
    }
    else if (entityName == "d")
    {
        Door* newDoor = new Door(x, y);
        addEntity(newDoor);
    }
}

void EntityManager::addEntity(Entity* entity)
{
    entities.insert(entity);
}

void EntityManager::destroyEntity(Entity* entity)
{
    entities.erase(entities.begin(), entities.end());
    /*for (auto it = entities.begin(); it != entities.end(); ++it)
        if (it->get() == entity)
            entities.erase(it);*/
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
        if (entity != character && hitbox.isColliding(entity->getHitbox()))
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
        if (entity != character && hitbox.isColliding(entity->getHitbox()))
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

