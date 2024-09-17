#include "Entity.h"

Vector2 Entity::getPosition() const
{
    return Position;
}

bool Entity::isHidden() const
{
    return hidden;
}

std::vector<std::string> Entity::getSprite() const
{
    return sprite;
}

void Entity::setSprite(const std::vector<std::string>& sprite)
{
    this->sprite = sprite;
}

void Entity::setPosition(const Vector2& Position)
{
    this->Position = Position;
}

void Entity::setHidden(bool hidden)
{
    this->hidden = hidden;
}
