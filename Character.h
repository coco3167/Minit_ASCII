#pragma once

#include "InteractableEntity.h"

class Character: public InteractableEntity
{
public:
    using InteractableEntity::InteractableEntity;

    // Getter
    int getLife() const;
    int getDirection() const;
    int getHorizontalSpeed() const;
    int getVerticalSpeed() const;
    bool checkIsDead() const;
    int getDamage() const;
    Sprite getLeftSprite() const;
    Sprite getRightSprite() const;
    Sprite getUpSprite() const;
    Sprite getDownSprite() const;

    // Setter
    void setDirection(int direction);
    void setDamage(int damage);
    void setVerticalSpeed(int verticalSpeed);
    void setHorizontalSpeed(int horizontalSpeed);
    void setLife(int life);
    void setSpriteRight(Sprite sprite);
    void setSpriteLeft(Sprite sprite);
    void setSpriteUp(Sprite sprite);
    void setSpriteDown(Sprite sprite);
    
    void moveHorizontal(int moveHorizontalSpeed);
    void moveVertical(int moveVertivalSpeed);
    void receiveDamage(int damage);
    
    void update(EntityManager& entity_manager) override;
    void onInteract(Entity* interactor) override;
    void reset() override;
    
private:
    int life = 1;
    int direction = 0;
    int horizontalSpeed = 2;
    int verticalSpeed = 1;
    int damage = 0;
    Sprite rightSprite = Sprite("playerUp.txt");
    Sprite leftSprite = Sprite("playerUp.txt");
    Sprite downSprite = Sprite("playerUp.txt");
    Sprite upSprite = Sprite("playerUp.txt");
};
