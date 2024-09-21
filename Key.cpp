#include "Key.h"

#include <iostream>
#include <ostream>

#include "EntityManager.h"
#include "Player.h"

Key::Key(int x, int y) : InteractableEntity(x, y, Sprite("key.txt")){}

void Key::onInteract(Entity* interactor)
{
    std::cout << "InteractableEntity::onInteract" << std::endl;
    if(Player* player = dynamic_cast<Player*>(interactor))
    {
        player->setKey(player->getKey() + 1);
        std::cout << player->getKey() << std::endl;
        //DESTROY KEY
        destroy = true;
    }
    
}

void Key::update(EntityManager& entity_manager)
{
    InteractableEntity::update(entity_manager);
    if (destroy)
    {
        destroy = false;
        entity_manager.destroyEntity(this);
    }
}
