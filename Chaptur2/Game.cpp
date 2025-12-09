
#include "Game.h"
#include "Actor.h"
#include "Ship.h"
#include "SDL.h"
#include "SpriteComponent.h"
#include "SDL_image.h"
#include "Asteroid.h"
#include <random>

Game::Game()
	:mIsRunning(true)
	, mWindow(nullptr)
	, mRenderer(nullptr)
	, mUpdatingActors(false)
{

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
	//SDL_GetTicks: SDL初期化からの経過時間をミリ秒で返す
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

	// ループ中の追加を防ぐためフラグを立てる
	mUpdatingActors = true;
	for (auto actor : mActors) {
		actor->ProcessInput(state);
	}
	mUpdatingActors = false;

	// 保留中の追加を mActors に移す
	if (!mPendingActors.empty()) {
		for (auto pending : mPendingActors) {
			mActors.emplace_back(pending);
		}
		mPendingActors.clear();
	}
}

void Game::UpdateGame() {
	while (SDL_TICKS_PASSED(mTicksCount + 16, SDL_GetTicks()));

	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0;

	if (deltaTime > 0.05f) {
		deltaTime = 0.05f;
	}

	mTicksCount = SDL_GetTicks();

	// ここもループ中に追加される可能性があるのでフラグを立てる
	mUpdatingActors = true;
	for (auto* actor : mActors) {
		actor->Update(deltaTime);
	}
	mUpdatingActors = false;

	// 保留中の追加を mActors に移す
	if (!mPendingActors.empty()) {
		for (auto pending : mPendingActors) {
			mActors.emplace_back(pending);
		}
		mPendingActors.clear();
	}

	std::vector<Actor*> deadActors;
	// 死んだアクターを削除
	for (auto actor : mActors) {
		if (actor->GetState() == Actor::EDead) {
			deadActors.emplace_back(actor);
		}
	}

	for (auto* actor : deadActors) {
		delete actor;
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

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> dist(0.0f, 768.0f);

	for (auto i = 0; i < 20; ++i) {
		Asteroid* asteroid = new Asteroid(this);
		asteroid->SetPosition(Vector2(dist(mt), dist(mt)));
	}
}

void Game::AddActor(Actor* actor) {
	if (mUpdatingActors) {
		mPendingActors.emplace_back(actor);
	}
	else {
		mActors.emplace_back(actor);
	}
}

void Game::RemoveActor(Actor* actor) {
	auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
	if (iter != mPendingActors.end()) {
		std::iter_swap(iter, mPendingActors.end() - 1);
		mPendingActors.pop_back();
	}

	iter = std::find(mActors.begin(), mActors.end(), actor);
	if (iter != mActors.end()) {
		std::iter_swap(iter, mActors.end() - 1);
		mActors.pop_back();
	}
}

void Game::AddAsteroid(Asteroid* asteroid) {
	mAsteroids.emplace_back(asteroid);
}

void Game::RemoveAsteroid(Asteroid* asteroid) {
	auto iter = std::find(mAsteroids.begin(), mAsteroids.end(), asteroid);
	if (iter != mAsteroids.end()) {
		mAsteroids.erase(iter);
	}
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
	auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
	if (iter != mSprites.end()) {
		mSprites.erase(iter);
	}
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
