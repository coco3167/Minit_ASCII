#include "EntityManager.h"
#include "InputManager.h"
#include "OutputManager.h"

int main()
{
    OutputManager outputManager;
    outputManager.setFixedConsoleSize(WIDTH, HEIGHT);
    Player player(0,0,5,5);
    InputManager inputManager = InputManager(&player);
    EntityManager entityManager = EntityManager();

    entityManager.addEntity(&player);

    while (true)
    {
        outputManager.clearBuffer(); //Reset buffer
        inputManager.getInput();
        entityManager.updateAll();

        outputManager.display(player);
        outputManager.drawBuffer(); //Blit buffer on screen

        Sleep(100); //Let the CPU breath
    }
    return 0;
}
