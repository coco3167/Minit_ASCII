#include "Map.h"

#include <fstream>
#include <iostream>
#include <sstream>
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
    
    std::string line;
    std::string entityName;
    int x, y ,w, h;
    
    // Reading the file line by line
    while (std::getline(file, line))
    {
        std::istringstream iss(line);

        // Try to read the name, x position and y position from the line
        if (iss >> entityName >> x >> y)
        {
            if (entityName == "w" and iss >> w >> h)
                entity_manager->createWall(x, y, w, h);
            else
                entity_manager->createEntity(entityName, x, y);
            
        }
        else
        {
            std::cerr << "Line incorrectly formatted: " << line << std::endl;
            file.close();
            return false;
        }
    }
    file.close();
    return true;
}

