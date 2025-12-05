#include "BGSpriteComponent.h"

BGSpriteComponent::BGSpriteComponent(Actor* actor, int drawOrder)
	:SpriteComponent(actor, drawOrder)
	, mScrollSpeed(100) {

};

void BGSpriteComponent::SetTextures(const std::vector<SDL_Texture*> textures) {	
	int count = 0;
	for (auto texture : textures) {
		BGTexture bg = BGTexture();
		bg.texture = texture;
		bg.offset = Vector2(count * mScreenSize.x , 0);
		count++;
		mBGTextures.emplace_back(bg);
	}
}

void BGSpriteComponent::Update(float deltaTime) {
	for (auto& bg : mBGTextures) {
		bg.offset.x += mScrollSpeed * deltaTime;

		if (bg.offset.x < -mScreenSize.x) {
			bg.offset.x = (mBGTextures.size() - 1) * mScreenSize.x-1;
		}
	}
}

void BGSpriteComponent::Draw(SDL_Renderer* renderer) {
	for (auto& bg: mBGTextures) {
		SDL_Rect rect;
		rect.w = mScreenSize.x;
		rect.h = mScreenSize.y;
		rect.x = bg.offset.x;
		rect.y = 0;

		SDL_RenderCopy(
			renderer,
			bg.texture,
			nullptr,
			&rect
		);
	}
}



