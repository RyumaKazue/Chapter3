#pragma once
#include "Component.h"
#include "Actor.h"
class MovementComponent :
    public Component
{
public:
    MovementComponent(class Actor* actor, int order = 10);
    void Update(float deltaTime) override;
    void ProcessInput(const Uint8* keyState) override;
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }

private:
    float mForwardSpeed;
    float mAngularSpeed;
};

