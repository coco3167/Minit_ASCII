#include <fstream>
#include <iostream>

#include "GameEngine.h"
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
    Player* myPlayer = entityManager.getPlayer();
    if (myPlayer == nullptr)
    {
        return EXIT_FAILURE;
    }
    OutputManager outputManager(*myPlayer, 6);
    InputManager inputManager = InputManager(*myPlayer);
    
    GameEngine gameEngine(entityManager, map, myPlayer, inputManager, outputManager);
    
    while (entityManager.loop())
    {
        gameEngine.update();

        Sleep(100); //Let the CPU breath
    }
}
