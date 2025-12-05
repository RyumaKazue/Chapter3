#include "Actor.h"
#include "Game.h"
#include "Component.h"

Actor::Actor(class Game* game)
	:mGame(game)
	,mPosition(Vector2())
{
	game->AddActor(this);
}

void Actor::AddComponent(Component* comp){ mComponents.push_back(comp); }

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