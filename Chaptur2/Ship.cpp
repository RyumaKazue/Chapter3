#include "Ship.h"
#include "SDL.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "BGSpriteComponent.h"
#include "SDL_image.h"

Ship::Ship(Game* game)
	: Actor(game)
	, mHorizontalSpeed(0)
	, mVerticalSpeed(0) {
	SpriteComponent* sp = new SpriteComponent(this, 100);
	sp->SetSize(64, 64);

	BGSpriteComponent* bg = new BGSpriteComponent(this, 10);
	std::vector<SDL_Texture*> textures = {
		game->GetTexture("Assets/Farback01.png"),
		game->GetTexture("Assets/Farback02.png")
	};
	
	bg->SetScreenSize(1024, 768);
	bg->SetTextures(textures);
	bg->SetScrollSpeed(-200);
}

void Ship::InputActor(const Uint8* keyState) {
	int verticalSpeed = 0;
	int horizontalSpeed = 0;

	if (keyState[SDL_SCANCODE_W]) {
		verticalSpeed += -mMaxVerticalSpeed;
	}

	if (keyState[SDL_SCANCODE_S]) {
		verticalSpeed += mMaxVerticalSpeed;
	}

	if (keyState[SDL_SCANCODE_D]) {
		horizontalSpeed += mMaxHorizontalSpeed;
	}

	if(keyState[SDL_SCANCODE_A]) {
		horizontalSpeed += -mMaxHorizontalSpeed;
	}

	SetSpeed(horizontalSpeed, verticalSpeed);
}

void Ship::UpdateActor(float deltaTime) {

	Vector2 pos = GetPosition();
	pos.x += mHorizontalSpeed * deltaTime;
	pos.y += mVerticalSpeed * deltaTime;

	SetPosition(pos);
}