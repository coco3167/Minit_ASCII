#include "EntityManager.h"
#include "Direction.h"
#include "Hitbox.h"
#include "InteractableEntity.h"
#include "Player.h"

void EntityManager::updateAll()
{
    for (auto it = entities.begin() ; it != entities.end() ; it++)
        (*it)->update(*this);
}

void EntityManager::addEntity(Entity const& entity)
{
    entities.insert(std::make_unique<Entity>(entity));
}

void EntityManager::destroyEntity(Entity* entity)
{
    for (auto it = entities.begin(); it != entities.end(); ++it)
        if (it->get() == entity)
            entities.erase(it);
}

int EntityManager::willCollideVertical(Character* character, int verticalSpeed) const
{
    Vector2 characterActualPosition = character->getPosition();
    int dir = character->getDirection();

    // In which direction we would go vertically
    if ((dir & UP) == UP) { characterActualPosition.y -= verticalSpeed; }
    if ((dir & DOWN) == DOWN) { characterActualPosition.y += verticalSpeed; }
   
    // Test we don't exit box vertically
    if (characterActualPosition.y < 0) { return 0; }
    if (characterActualPosition.y + character->getHitbox().h > WinSize::getInstance()->size.X) { return 0; }

    // Get Hitbox in place where we would like to be
    Hitbox hitbox = (character->getHitbox());
    hitbox.y = characterActualPosition.y;
    
    // test collision with others entity
    for (auto it = entities.begin(); it != entities.end(); it++)
    {
        Entity* entity = it->get();
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
   
    // Test we don't exit box
    if (characterActualPosition.x < 0) { return false; }
    if (characterActualPosition.x + character->getHitbox().w > WinSize::getInstance()->size.X) { return false; }

    // Get Hitbox in place where we would like to be
    Hitbox hitbox = (character->getHitbox());
    hitbox.x = characterActualPosition.x;
    
    // test collision with others entity
    for (auto it = entities.begin(); it != entities.end(); it++)
    {
        Entity* entity = it->get();
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