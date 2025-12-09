#include "Ship.h"
#include "SDL.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "BGSpriteComponent.h"
#include "SDL_image.h"
#include "InputComponent.h"

Ship::Ship(Game* game)
	: Actor(game)
	, mHorizontalSpeed(0)
	, mVerticalSpeed(0) {
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

}

void Ship::UpdateActor(float deltaTime) {

}