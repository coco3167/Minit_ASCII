#pragma once
#include "EntityManager.h"
#include "InputManager.h"
#include "Map.h"
#include "NYTimer.h"
#include "OutputManager.h"

class GameEngine
{
public:
    GameEngine(EntityManager entityManager, Map map, Player* myPlayer, InputManager inputManager, OutputManager outputManager);
    void update();

private:
    EntityManager entityManager;
    Map map;
    Player* myPlayer;
    InputManager inputManager;
    OutputManager outputManager;
    NYTimer timer;

    void restartGame();
    void initPlayer() const;    
};
