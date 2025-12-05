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

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_RenderFillRect(renderer, &rect);
}