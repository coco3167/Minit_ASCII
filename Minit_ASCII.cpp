#include "InputManager.h"

int main(int argc, char* argv[])
{
    Player player = Player();
    InputManager inputManager = InputManager(&player);
    while(true)
    {
        inputManager.GetInput();
    }
    
    return 0;
}
