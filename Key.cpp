﻿#include "Key.h"

#include "Player.h"

void Key::onInteract(Entity* interactor)
{
    if(Player* player = static_cast<Player*>(interactor))
    {
        player->setKey(player->getKey() + 1);
    }
    //DESTROY KEY
}
