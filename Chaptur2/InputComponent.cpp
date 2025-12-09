#include "InputComponent.h"

InputComponent::InputComponent(Actor* actor, int order)
	:MovementComponent(actor, order) {

}

void InputComponent::ProcessInput(const Uint8* keyState) {
	//キー入力から速度を設定
	float forwardSpeed = 0.0f;
	if (keyState[SDL_SCANCODE_W]) {
		forwardSpeed += mMaxForwardSpeed;
	}

	if(keyState[SDL_SCANCODE_S]) {
		forwardSpeed -= mMaxForwardSpeed;
	}
	SetForwardSpeed(forwardSpeed);
	
	//キー入力から回転速度を設定
	float angularSpeed = 0.0f;
	if(keyState[SDL_SCANCODE_D]) {
		angularSpeed -= mMaxAngularSpeed;
	}

	if(keyState[SDL_SCANCODE_A]) {
		angularSpeed += mMaxAngularSpeed;
	}
	SetAngularSpeed(angularSpeed);

}

