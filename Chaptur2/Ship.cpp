#include "Ship.h"
#include "SDL.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "BGSpriteComponent.h"
#include "SDL_image.h"
#include "InputComponent.h"
#include "Laser.h"

Ship::Ship(Game* game)
	: Actor(game) {
	// スプライトコンポーネントを追加
	SpriteComponent* sp = new SpriteComponent(this, 100);
	sp->SetSize(64, 64);
	SDL_Texture* tex = game->GetTexture("Assets/Ship01.png");
	sp->SetTexture(tex);

	//インプットコンポーネントを追加
	InputComponent* ic = new InputComponent(this);
	ic->SetMaxForwardSpeed(300.0f);
	ic->SetMaxxAngularSpeed(3.14);

	//背景コンポーネントを追加
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
	if(keyState[SDL_SCANCODE_SPACE] && mLaserCooldown < 0) {
		//レーザー発射
		Actor* laser = new Laser(GetGame());
		Vector2 laserPos = mPosition + GetForward() * 50.0f;
		laser->SetPosition(laserPos);
		laser->SetRotation(mRotation);
		mLaserCooldown = mMaxLaserCooldown;
	}
}

void Ship::UpdateActor(float deltaTime) {
	mLaserCooldown--;
}