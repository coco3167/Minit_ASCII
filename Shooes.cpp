#include "Shooes.h"

#include "Player.h"

Shooes::Shooes(int x, int y) : InteractableEntity(x, y, Sprite("shooes.txt")) { }

void Shooes::onInteract(Entity* interactor)
{
    Player* player = dynamic_cast<Player*>(interactor);
    if (player != nullptr)
    {
        player->setHorizontalSpeed(player->getHorizontalSpeed() + 2);
        player->setVerticalSpeed(player->getVerticalSpeed() + 2);
        setHidden(true);
        setCollision(false);
    }
}

