#pragma once
#include "Component.h"

class SpriteComponent : public Component {
public:
	SpriteComponent(class Actor* actor, int drawOrder);
	virtual void Draw(SDL_Renderer* renderer);
	int GetDrawOrder() const { return mDrawOrder; };
	void SetSize(const int width, const int height) { mWidth = width; mHeight = height; };
private:
	int mDrawOrder;
	int	mWidth;
	int mHeight;
};