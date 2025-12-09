#include "Asteroid.h"
#include "Game.h"
#include "MovementComponent.h"
#include "SpriteComponent.h"
#include "CircleComponent.h"

Asteroid::Asteroid(class Game* game)
	:Actor(game) {
	MovementComponent* mc = new MovementComponent(this);
	mc->SetForwardSpeed(40.0f);
	mc->SetAngularSpeed(0.5f);

	SpriteComponent* sc = new SpriteComponent(this, 50);
	sc->SetSize(64, 64);
	SDL_Texture* tex = game->GetTexture("Assets/Asteroid.png");
	sc->SetTexture(tex);

	CircleComponent* cc = new CircleComponent(this, 32);
	mCircleComponent = cc;

	game->AddAsteroid(this);
}

Asteroid::~Asteroid() {
	mGame->RemoveAsteroid(this);
}


void Asteroid::UpdateActor(float deltaTime) {
}