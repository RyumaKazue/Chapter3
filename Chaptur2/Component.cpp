#include "Component.h"
#include "SDL.h"
#include "Actor.h"

Component::Component(Actor* actor, int order)
	:mActor(actor)
	, mOrder(order) {
	actor->AddComponent(this);
}

void Component::Update(float deltaTime) {

}

void Component::ProcessInput(const Uint8* keyState) {
}