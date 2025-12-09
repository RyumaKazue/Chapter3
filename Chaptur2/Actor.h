#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2.h"
#include "Game.h"
#include "Component.h"
#include <cmath>

class Actor {
public:
	Actor(class Game* game);
	void Update(float deltaTime);
	void ProcessInput(const Uint8* keyState);
	void UpdateComponents(float deltaTime);
	virtual void UpdateActor(float deltaTime);
	Vector2 GetPosition() const { return mPosition; };
	void SetPosition(const Vector2 pos) { mPosition = pos; };
	void SetRotation(float rotation) { mRotation = rotation; };
	float GetRotation() const { return mRotation; };
	Game* GetGame() const { return mGame; };
	virtual void InputActor(const Uint8* keyState);
	void AddComponent(Component* comp);
	Vector2 GetForward() const { return Vector2(cosf(mRotation), -sinf(mRotation)); };
protected:
	Game* mGame;
	Vector2 mPosition;
	Vector2 mScale;
	float mRotation;
	std::vector<class Component*> mComponents;
};