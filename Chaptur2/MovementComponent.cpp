#include "MovementComponent.h"


MovementComponent::MovementComponent(Actor* actor, int order)
	:Component(actor, order)
	, mForwardSpeed(0.0f)
	, mAngularSpeed(0.0f) {

}

void MovementComponent::ProcessInput(const Uint8* keyState) {

}

void MovementComponent::Update(float deltaTime) {
	//回転から向きを更新
	float angular = mActor->GetRotation() + mAngularSpeed * deltaTime;
	mActor->SetRotation(angular);

	//スピードから位置を更新
	Vector2 pos = mActor->GetPosition() + mActor->GetForward() * mForwardSpeed * deltaTime;
	mActor->SetPosition(pos);
}

