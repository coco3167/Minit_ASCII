#include "InteractableEntity.h"

InteractableEntity::InteractableEntity(int x, int y, Sprite sprite) : Entity(x, y, sprite) { }

void InteractableEntity::reset()
{
    Entity::reset();
    setHidden(false);
    setCollision(true);
}
