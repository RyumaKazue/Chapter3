#include "Actor.h"
#include "Game.h"
#include "Component.h"

Actor::Actor(class Game* game)
	:mGame(game)
	,mState(EActive)
	,mPosition(Vector2())
	, mRotation(0.0f)
{
	game->AddActor(this);
}

Actor::~Actor() {
	mGame->RemoveActor(this);
	// コンポーネントを削除
	while (!mComponents.empty()) {
		delete mComponents.back();
	}
}

void Actor::AddComponent(Component* comp){ mComponents.push_back(comp); }

void Actor::RemoveComponent(Component* comp) {
	auto iter = std::find(mComponents.begin(), mComponents.end(), comp);
	if (iter != mComponents.end()) {
		mComponents.erase(iter);
	}
}

void Actor::Update(float deltaTime) {
	UpdateComponents(deltaTime);
	UpdateActor(deltaTime);
}

void Actor::ProcessInput(const Uint8* keyState) {
	for (auto comp : mComponents) {
		comp->ProcessInput(keyState);
	}
	InputActor(keyState);
}

void Actor::InputActor(const Uint8* keyState) {

}

void Actor::UpdateActor(float deltaTime) {

}

void Actor::UpdateComponents(float deltaTime) {
	for (auto comp : mComponents) {
		comp->Update(deltaTime);
	}
}