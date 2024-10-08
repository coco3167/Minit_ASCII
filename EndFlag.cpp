#include "EndFlag.h"

EndFlag::EndFlag(int x, int y): InteractableEntity(x,y,Sprite("endFlag.txt")), triggered(false)
{}

void EndFlag::onInteract(Entity* interactor)
{
	triggered = true;
}

bool EndFlag::isTriggered() const
{
	return triggered;
}
