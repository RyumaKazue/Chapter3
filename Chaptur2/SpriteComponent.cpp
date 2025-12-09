#include "SpriteComponent.h"
#include "Actor.h"

SpriteComponent::SpriteComponent(Actor* actor, int drawOrder)
	:Component(actor, 100)
	, mDrawOrder(drawOrder)
	, mWidth(0)
	, mHeight(0) {
	actor->GetGame()->AddSprite(this);
}

void SpriteComponent::Draw(SDL_Renderer* renderer) {
	SDL_Rect rect;
	rect.w = mWidth;
	rect.h = mHeight;
	rect.x = static_cast<int>(GetActor()->GetPosition().x) - rect.w / 2;
	rect.y = static_cast<int>(GetActor()->GetPosition().y) - rect.h / 2;

	if (mTexture) {
		const float Pi = 3.14159265f;
		// Actor ‚Ì‰ñ“]‚Íƒ‰ƒWƒAƒ“‚È‚Ì‚ÅA“x‚É•ÏŠ·‚µ‚Ä SDL ‚É“n‚·
		float degrees = mActor->GetRotation() * 180.0f / Pi;
		// SDL ‚Í³‚ÌŠp“x‚ÅŒv‰ñ‚è‚É‰ñ“]‚·‚é‚½‚ß•„†‚ğ”½“]‚µ‚Ä“n‚·
		SDL_RenderCopyEx(
			renderer,
			mTexture,
			nullptr,
			&rect,
			-degrees,
			nullptr,
			SDL_FLIP_NONE);
	}
	else {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);
	}

}