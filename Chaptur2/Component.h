#pragma once
#include <SDL.h>
#include "Game.h"

class Component {
public:
	Component(class Actor* actor, int order);
	virtual void Update(float deltaTime);
	virtual void ProcessInput(const Uint8* keyState);
	const Actor* GetActor() const { return mActor; };
	int GetOrder() const { return mOrder; };
protected:
	int mOrder;
	Actor* mActor;
};