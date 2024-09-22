#include "GameEngine.h"

GameEngine::GameEngine(EntityManager entityManager, Map map, Player* myPlayer, InputManager inputManager,
    OutputManager outputManager) : entityManager(entityManager), map(map), myPlayer(myPlayer), inputManager(inputManager), outputManager(outputManager) 
{
    timer.start();
    initPlayer();
    outputManager.setConsoleStyle();
}

void GameEngine::update()
{
    if (timer.getElapsedSeconds(false) >= 8.f || myPlayer->checkIsDead()) // WARNING PUT 60.f
    {
        restartGame();
        timer.restart();
    }
    outputManager.clearBuffer(); //Reset buffer
    inputManager.getInput(); // Get PlayerInput
    entityManager.updateAll();
    outputManager.displayEntities(entityManager.getEntities()); // Display All Entities
    outputManager.drawBuffer(); //Blit buffer on screen
}

void GameEngine::restartGame()
{
    entityManager.resetEntities();
    initPlayer();
}

void GameEngine::initPlayer() const
{
    /*myPlayer = entityManager.getPlayer();
    if (myPlayer == NULL)
        return false;*/

    myPlayer->reset();
    myPlayer->setKey(0);
    myPlayer->setDamage(0);
    myPlayer->setVerticalSpeed(1);
    myPlayer->setHorizontalSpeed(2);
}