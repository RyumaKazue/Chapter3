#include "Game.h"
#include "Actor.h"
#include "Ship.h"
#include "SDL.h"
#include "SpriteComponent.h"
#include "SDL_image.h"

Game::Game()
	:mIsRunning(true)
	,mWindow(nullptr)
	,mRenderer(nullptr) {

}

bool Game::Initialize() {
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0) {
		return false;
	}

	mWindow = SDL_CreateWindow(
		"Game Programming in C++ (Chaptur2)",
		100, 100, 1024, 768, 0
	);

	if (!mWindow) {
		return false;
	}

	mRenderer = SDL_CreateRenderer(
		mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!mRenderer) {
		return false;
	}
	//SDL_GetTicks: SDL‰Šú‰»‚©‚ç‚ÌŒo‰ßŽžŠÔ‚ðƒ~ƒŠ•b‚Å•Ô‚·
	mTicksCount = SDL_GetTicks();

	LoadData();

	return true;
}

void Game::RunLoop() {
	while (mIsRunning) {
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::ProcessInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			mIsRunning = false;
			return;
		}
	}


	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_ESCAPE]) {
		mIsRunning = false;
	}

	for (auto actor : mActors) {
		actor->ProcessInput(state);
	}

}

void Game::UpdateGame() {
	while (SDL_TICKS_PASSED(mTicksCount + 16, SDL_GetTicks()));

	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0;

	if (deltaTime > 0.05f) {
		deltaTime = 0.05f;	
	}

	mTicksCount = SDL_GetTicks();

	for (auto actor : mActors) {
		actor->Update(deltaTime);
	}
}
void Game::GenerateOutput() {
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderClear(mRenderer);

	for (auto sprite : mSprites) {
		sprite->Draw(mRenderer);
	}

	SDL_RenderPresent(mRenderer);
}

void Game::LoadData() {
	Ship* ship = new Ship(this);
	ship->SetPosition(Vector2(512.0f, 384.0f));
	ship->SetMaxSpeed(300, 300);
}

void Game::AddActor(Actor* actor) {
	mActors.emplace_back(actor);
}	

void Game::RemoveActor(Actor* actor) {
	
}

void Game::AddSprite(SpriteComponent* sprite) {
	int myDrawOrder = sprite->GetDrawOrder();
	auto iter = mSprites.begin();
	for (; iter != mSprites.end(); ++iter) {
		if (myDrawOrder < (*iter)->GetDrawOrder()) {
			break;
		}
	}

	mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite) {

}

SDL_Texture* Game::GetTexture(const std::string& fileName) {
	SDL_Texture* tex = nullptr;
	auto iter = mTextures.find(fileName);
	if (iter != mTextures.end()) {
		tex = iter->second;
	}
	else {
		SDL_Surface* suf = IMG_Load(fileName.c_str());
		if (!suf) {
			return nullptr;
		}

		tex = SDL_CreateTextureFromSurface(mRenderer, suf);
		
		SDL_FreeSurface(suf);
		
		if (!suf) {
			return nullptr;
		}

		mTextures.emplace(fileName.c_str(), tex);
	}

	return tex;
}