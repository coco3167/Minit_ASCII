#pragma once
#include "InteractableEntity.h"
class EndFlag: public InteractableEntity
{
public:
	EndFlag(int x, int y);
	void onInteract(Entity* interactor) override;
	bool isTriggered() const;

private:
	bool triggered = false;
};

