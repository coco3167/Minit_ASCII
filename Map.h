#pragma once
#include "Player.h"

class Map
{
public:
    Map(EntityManager* entity_manager);
    bool initMap();
    
private:
    EntityManager* entity_manager;
};
