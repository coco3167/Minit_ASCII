#include "Entity.h"

/*
====================
Getter
====================
*/

Vector2 Entity::getPosition() const
{
    return position;
}

bool Entity::isHidden() const
{
    return hidden;
}

std::vector<std::string> Entity::getSprite() const
{
    return sprite;
}

/*
====================
Setter
====================
*/

void Entity::setSprite(const std::vector<std::string>& sprite)
{
    this->sprite = sprite;
}

void Entity::setPosition(const Vector2& position)
{
    this->position = position;
}

void Entity::setHidden(bool hidden)
{
    this->hidden = hidden;
}
