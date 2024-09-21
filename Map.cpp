#include "Map.h"

#include <fstream>
#include <iostream>
#include <string>

#include "EntityManager.h"


Map::Map(EntityManager* entity_manager) : entity_manager(entity_manager) { }

// Init Entity Manager with a level file
bool Map::initMap()
{
    std::string fileName = "level.txt";
    std::ifstream file(fileName);

    //Check can open file
    if (!file.is_open())
    {
        std::cerr << "Error : Can't open level file " << fileName << std::endl;
        return false;
    }
    std::string entityName;
    int x, y;

    // Reading the file line by line
    while (file >> entityName >> x >> y)
    {
    file >> entityName >> x >> y;
        entity_manager->createEntity(entityName, x, y);
    }
    file.close();
    return true;
}

