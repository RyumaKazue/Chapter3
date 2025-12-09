#pragma once
#include "MovementComponent.h"
class InputComponent :
    public MovementComponent
{

public:
    InputComponent(class Actor* actor, int order = 20);
    void ProcessInput(const Uint8* keyState) override;
    void SetMaxForwardSpeed(float speed) { mMaxForwardSpeed = speed; };
    void SetMaxxAngularSpeed(float speed) { mMaxAngularSpeed = speed; };

private:
    float mMaxForwardSpeed;
    float mMaxAngularSpeed;
};

