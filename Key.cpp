#include "Key.h"

#include <iostream>
#include <ostream>

#include "EntityManager.h"
#include "Player.h"

Key::Key(int x, int y) : InteractableEntity(x, y, Sprite("key.txt")){}

void Key::onInteract(Entity* interactor)
{
    Player* player = dynamic_cast<Player*>(interactor);
    
    if(player != nullptr)
    {
        player->addKey();
        //DESTROY KEY
        destroy = true;
    }
}

void Key::update(EntityManager& entity_manager)
{
    InteractableEntity::update(entity_manager);
}
