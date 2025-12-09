#pragma once
#include "Component.h"

class SpriteComponent : public Component {
public:
	SpriteComponent(class Actor* actor, int drawOrder);
	virtual void Draw(SDL_Renderer* renderer);
	int GetDrawOrder() const { return mDrawOrder; };
	void SetSize(const int width, const int height) { mWidth = width; mHeight = height; };
	void SetTexture(SDL_Texture* texture) { mTexture = texture; };
private:
	SDL_Texture* mTexture;
	int mDrawOrder;
	int	mWidth;
	int mHeight;
};