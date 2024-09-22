#include <fstream>
#include <iostream>

#include "EntityManager.h"
#include "InputManager.h"
#include "Map.h"
#include "OutputManager.h"


int main()
{
    // Manage Debug file
    std::ofstream debugFile("DEBUG.txt", std::ios::out | std::ios::trunc);
    std::cout.rdbuf(debugFile.rdbuf());
    
    // Create Level (init entity manager)
    EntityManager entityManager = EntityManager();
    Map map = Map(&entityManager);
    map.initMap();

    // Check if the player in entityManager has been initialized
    Player* myPlayer = entityManager.getPlayer();
    if (myPlayer == nullptr)
    {
        return EXIT_FAILURE;
    }
    
    OutputManager outputManager(*myPlayer, 6);
    outputManager.setConsoleStyle();
    InputManager inputManager = InputManager(myPlayer);
    
    while (true)
    {
        outputManager.clearBuffer(); //Reset buffer
        inputManager.getInput();
        entityManager.updateAll();
        outputManager.displayEntities(entityManager.getEntities());
        outputManager.drawBuffer(); //Blit buffer on screen

        Sleep(100); //Let the CPU breath
    }
}
