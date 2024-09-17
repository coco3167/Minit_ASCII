#include "InputManager.h"
#include "OutputManager.h"

int main()
{
    OutputManager outputManager;
    outputManager.setFixedConsoleSize(WIDTH, HEIGHT);
    Player player = Player();
    InputManager inputManager = InputManager(&player);

    while (true) {
        outputManager.clearBuffer();  // Réinitialiser le buffer
        inputManager.GetInput();
        outputManager.drawBuffer();  // Afficher le buffer sur la console

        Sleep(100);  // Pause pour ralentir l'affichage
    }
    return 0;
}
