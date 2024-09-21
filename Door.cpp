#include "Door.h"

#include "Player.h"

Door::Door(int x, int y) : InteractableEntity(x, y, Sprite("doorClosed.txt")){}

void Door::onInteract(Entity* interactor)
{
    if(Player* player = dynamic_cast<Player*>(interactor))
    {
        if(player->getKey())
        {
            openDoor();
        }
    }
}

void Door::openDoor()
{
    if (!open)
    {
        // OPEN DOOR
        open = true;
    }
}
