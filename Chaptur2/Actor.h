#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2.h"
#include "Game.h"
#include "Component.h"
#include <cmath>

class Actor {
public:
	enum State {
		EActive,
		EPaused,
		EDead
	};

	Actor(class Game* game);
	virtual ~Actor();

	void Update(float deltaTime);
	
	void ProcessInput(const Uint8* keyState);
	void UpdateComponents(float deltaTime);
	void InputComponents(const Uint8* keyState);
	virtual void UpdateActor(float deltaTime);
	Vector2 GetPosition() const { return mPosition; };
	void SetPosition(const Vector2 pos) { mPosition = pos; };
	void SetRotation(float rotation) { mRotation = rotation; };
	void SetState(State state) { mState = state; };
	float GetRotation() const { return mRotation; };
	Game* GetGame() const { return mGame; };
	virtual void InputActor(const Uint8* keyState);
	void AddComponent(Component* comp);
	Vector2 GetForward() const { return Vector2(cosf(mRotation), -sinf(mRotation)); };
	State GetState() const { return mState; };
	void RemoveComponent(Component* comp);
	
protected:
	Game* mGame;
	Vector2 mPosition;
	Vector2 mScale;
	float mRotation;
	std::vector<class Component*> mComponents;
	State mState;
};