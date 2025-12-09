#pragma once
#include<SDL.h>
#include<string>
#include<vector>
#include<unordered_map>

class Game {
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	void AddAsteroid(class Asteroid* asteroid);
	void RemoveAsteroid(class Asteroid* asteroid);

	std::vector<class Asteroid*> GetAsteroids() { return mAsteroids; };

	SDL_Texture* GetTexture(const std::string& fileName);

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	bool mIsRunning;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	std::vector<class Actor*> mActors;
	std::vector<class Actor*> mPendingActors;
	std::vector<class SpriteComponent*> mSprites;
	std::vector<class Asteroid*> mAsteroids;

	std::unordered_map<std::string, SDL_Texture*> mTextures;
	float mTicksCount;
	void LoadData();
	bool mUpdatingActors;
};