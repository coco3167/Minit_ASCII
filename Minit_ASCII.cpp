#include "InputManager.h"
#include "OutputManager.h"

int main()
{
    OutputManager outputManager;
    outputManager.setFixedConsoleSize(WIDTH, HEIGHT);
    Player player = Player();
    InputManager inputManager = InputManager(&player);

    while (true) {
        outputManager.clearBuffer();
        inputManager.GetInput();
        outputManager.drawBuffer(); 

        Sleep(100);
    }
    return 0;
}
