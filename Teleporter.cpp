#include "Teleporter.h"

#include "Direction.h"
#include "Player.h"

Teleporter::Teleporter(int x, int y) : InteractableEntity(x, y, Sprite("teleporter.txt")) {}

void Teleporter::onInteract(Entity* interactor)
{
    Player* player = dynamic_cast<Player*>(interactor);
    if (getOtherTeleporter() != nullptr && player != nullptr)
    {
        player->setDirection(DOWN);
        interactor->setPosition({getOtherTeleporter()->getPosition().x, getOtherTeleporter()->getPosition().y + getSprite().getHeight()});
    }
}

Teleporter* Teleporter::getOtherTeleporter() { return otherTeleporter; }

void Teleporter::setOtherTeleporter(Teleporter* other) { this->otherTeleporter = other; }
