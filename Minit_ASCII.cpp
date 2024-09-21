#include <fstream>
#include <iostream>

#include "EntityManager.h"
#include "InputManager.h"
#include "OutputManager.h"

int main()
{
    std::ofstream debugFile("DEBUG.txt", std::ios::out | std::ios::trunc);
    std::cout.rdbuf(debugFile.rdbuf());
    
    Player player(0,0);
    OutputManager outputManager(player);
    outputManager.setFixedConsoleSize(WIDTH, HEIGHT);
    outputManager.setConsoleStyle();
    Player player2(6, 6);
    Player player3(20, 6);
    Player player4(12, 20);
    InputManager inputManager = InputManager(&player);
    EntityManager entityManager = EntityManager();

    entityManager.addEntity(&player);
    entityManager.addEntity(&player2);
    entityManager.addEntity(&player3);
    entityManager.addEntity(&player4);
    
    while (true)
    {
        outputManager.clearBuffer(); //Reset buffer
        inputManager.getInput();
        entityManager.updateAll();

        outputManager.display(player);
        outputManager.display(player2);
        outputManager.display(player3);
        outputManager.display(player4);
        outputManager.drawBuffer(); //Blit buffer on screen

        Sleep(100); //Let the CPU breath
    }
}
