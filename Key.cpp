#include "Key.h"

#include "EntityManager.h"
#include "Player.h"

Key::Key(int x, int y) : InteractableEntity(x, y, Sprite("key.txt")){}

void Key::onInteract(Entity* interactor)
{
    Player* player = dynamic_cast<Player*>(interactor);
    
    if(player != nullptr)
    {
        player->addKey();
        setHidden(true);
        setCollision(false);
    }
}

void Key::update(EntityManager& entity_manager) { InteractableEntity::update(entity_manager); }

void Key::reset() { InteractableEntity::reset(); }
