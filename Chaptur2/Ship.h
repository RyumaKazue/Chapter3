#pragma once
#include "Actor.h"

class Ship : public Actor {
public:
	Ship(class Game* game);

	void UpdateActor(float deltaTime) override;

	void InputActor(const Uint8* keyState);


private:
	int mLaserCooldown = 0;
	int mMaxLaserCooldown = 30;
};