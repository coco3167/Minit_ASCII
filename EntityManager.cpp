#include "EntityManager.h"

#include <iostream>

#include "Direction.h"
#include "Door.h"
#include "Key.h"
#include "Monster1.h"
#include "Monster2.h"
#include "Spawn.h"
#include "Wall.h"
#include "Shooes.h"


EntityManager::~EntityManager()
{
    //removeAllEntities();
}

void EntityManager::updateAll()
{
    for (auto it = entities.begin() ; it != entities.end() ; it++)
        (*it)->update(*this);
}

// Reset entity settings to basic ones
void EntityManager::resetEntities()
{
    for (auto it = entities.begin() ; it != entities.end() ; it++)
        (*it)->reset();
}

// Free entities and clear unordered_set
void EntityManager::removeAllEntities()
{
    for (auto it = entities.begin(); it != entities.end(); it++)
        delete *it;
    entities.clear();
}

// Create Entity from file
void EntityManager::createEntity(std::string entityName, int x, int y)
{
    if (entityName == "p") // Player
    {
        Player* newPlayer = new Player(x, y);
        addEntity(newPlayer);
        if (player == nullptr) player = newPlayer;
    }
    else if (entityName == "k") // Key
        addEntity(new Key(x, y));

    else if (entityName == "d") // Door
        addEntity(new Door(x, y));

    else if (entityName == "m1") // Monster1
        addEntity(new Monster1(x, y));

    else if (entityName == "m2") // Monster 2
        addEntity(new Monster2(x, y));

    else if (entityName == "s") // Spawn
        addEntity(new Spawn(x, y));

    else if (entityName == "t") // Teleporter
    {
        Teleporter* newTeleporter = new Teleporter(x, y);
        addEntity(newTeleporter);
        if (teleporter1 == nullptr)
            teleporter1 = newTeleporter;
        else if (teleporter2 == nullptr)
        {
            teleporter2 = newTeleporter;
            // make couple
            teleporter1->setOtherTeleporter(teleporter2);
            teleporter2->setOtherTeleporter(teleporter1);

            // to make other couple of teleporter
            teleporter1 = nullptr;
            teleporter2 = nullptr;
        }
    }

    else if (entityName == "ef") // EndFlaf
    {
        EndFlag* newEndFlag = new EndFlag(x, y);
        addEntity(newEndFlag);
        if (endFlag == nullptr)
            endFlag = newEndFlag;
    }

    else if (entityName == "sh") // Shooes
        addEntity(new Shooes(x, y));
}

void EntityManager::createWall(int x, int y, int w, int h)
{
    addEntity(new Wall(x, y, w, h));
}

// Add entity to unordered_set 
void EntityManager::addEntity(Entity* entity)
{
    entities.insert(entity);
}

// free entity and clear it in the unordered_set
void EntityManager::destroyEntity(Entity* entity)
{
    entities.erase(entity);
    delete entity;
}

// Check vertical Collision
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

// Check Horizontal Collision
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

// Main Loop boolean
bool EntityManager::loop() { return !endFlag->isTriggered(); }

