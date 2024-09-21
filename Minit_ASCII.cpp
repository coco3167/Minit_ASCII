#include <fstream>
#include <iostream>

#include "EntityManager.h"
#include "InputManager.h"
#include "Key.h"
#include "Map.h"
#include "OutputManager.h"


int main()
{
    // Manage Debug file
    std::ofstream debugFile("DEBUG.txt", std::ios::out | std::ios::trunc);
    std::cout.rdbuf(debugFile.rdbuf());
        
    //Player player(0,0);
    //Player player2(6, 6);
    //Player player3(20, 6);
    //Key key(12, 20);
    
    EntityManager entityManager = EntityManager();
    
    // Create Level (init entity manager)
    Map map = Map(&entityManager);
    map.initMap();
    
    Player* myPlayer = entityManager.getPlayer();
    if (myPlayer == nullptr)
    {
        return EXIT_FAILURE;
    }
    
    OutputManager outputManager(*myPlayer);
    outputManager.setConsoleStyle();
    InputManager inputManager = InputManager(myPlayer);
    

    //entityManager.addEntity(&player);
    //entityManager.addEntity(&player2);
    //entityManager.addEntity(&player3);
    //entityManager.addEntity(&player4);
    //entityManager.addEntity(&key);
    
    while (true)
    {
        outputManager.clearBuffer(); //Reset buffer
        inputManager.getInput();
        entityManager.updateAll();
        
        //outputManager.display(*player);
        outputManager.display(*myPlayer);
        //outputManager.display(player2);
        //outputManager.display(player3);
        //outputManager.display(player4);
        //outputManager.display(key);
        //outputManager.drawBuffer(); //Blit buffer on screen

        Sleep(100); //Let the CPU breath
    }
}
