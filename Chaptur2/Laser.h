#pragma once
#include "Actor.h"
class Laser :
    public Actor
{
public:
    Laser(class Game* game);
    void UpdateActor(float deltaTime) override;
    void InputActor(const Uint8* keyState) override;
private:
    float regularSpeed = 100.0f;
};

