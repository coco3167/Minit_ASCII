#include "EntityManager.h"
#include "InputManager.h"
#include "OutputManager.h"

int main()
{
    OutputManager outputManager;
    outputManager.setFixedConsoleSize(WIDTH, HEIGHT);
    Player player = Player();
    InputManager inputManager = InputManager(&player);
    EntityManager entityManager = EntityManager();

    entityManager.addEntity(&player);

    while (true)
    {
        outputManager.clearBuffer();  // R�initialiser le buffer
        inputManager.getInput();
        entityManager.updateAll();
        outputManager.drawBuffer();  // Afficher le buffer sur la console

        Sleep(100);  // Pause pour ralentir l'affichage
    }
    return 0;
}
