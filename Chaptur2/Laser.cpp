#include "Laser.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"

Laser::Laser(class Game* game)
	:Actor(game){
	MovementComponent* mc = new MovementComponent(this);
	mc->SetForwardSpeed(regularSpeed);
	mc->SetAngularSpeed(0.0f);

	SpriteComponent* sc = new SpriteComponent(this, 100);
	sc->SetSize(32, 32);
	SDL_Texture* tex = game->GetTexture("Assets/Laser.png");
	sc->SetTexture(tex);
}

void Laser::UpdateActor(float deltaTime) {

}

void Laser::InputActor(const Uint8* keyState) {

}