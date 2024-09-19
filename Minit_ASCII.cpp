#include <fstream>
#include <iostream>

#include "EntityManager.h"
#include "InputManager.h"
#include "OutputManager.h"

int main()
{
    std::ofstream debugFile("DEBUG.txt", std::ios::out | std::ios::trunc);
    std::cout.rdbuf(debugFile.rdbuf());
    
    OutputManager outputManager;
    outputManager.setFixedConsoleSize(WIDTH, HEIGHT);
    Player player(0,0);
    Player player2(6,6);
    InputManager inputManager = InputManager(&player);
    EntityManager entityManager = EntityManager();

    entityManager.addEntity(&player);
    entityManager.addEntity(&player2);
    
    while (true)
    {
        outputManager.clearBuffer(); //Reset buffer
        inputManager.getInput();
        entityManager.updateAll();

        outputManager.display(player);
        outputManager.display(player2);
        outputManager.drawBuffer(); //Blit buffer on screen

        Sleep(100); //Let the CPU breath
    }
}
