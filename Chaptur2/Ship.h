#pragma once
#include "Actor.h"

class Ship : public Actor {
public:
	Ship(class Game* game);

	void UpdateActor(float deltaTime) override;

	void InputActor(const Uint8* keyState);

	void SetMaxSpeed(const int maxHorizontalSpeed, const int maxVerticalSpeed) {
		mMaxHorizontalSpeed = maxHorizontalSpeed;
		mMaxVerticalSpeed = maxVerticalSpeed;
	};



private:
	int mHorizontalSpeed;
	int mVerticalSpeed;

	int mMaxHorizontalSpeed;
	int mMaxVerticalSpeed;

	void SetSpeed(const int horizontalSpeed, const int verticalSpeed) {
		mHorizontalSpeed = horizontalSpeed;
		mVerticalSpeed = verticalSpeed;
	};
};