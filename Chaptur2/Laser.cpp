#include "Laser.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"
#include "CircleComponent.h"
#include "Asteroid.h"

Laser::Laser(class Game* game)
	:Actor(game){
	MovementComponent* mc = new MovementComponent(this);
	mc->SetForwardSpeed(regularSpeed);
	mc->SetAngularSpeed(0.0f);

	SpriteComponent* sc = new SpriteComponent(this, 100);
	sc->SetSize(32, 32);
	SDL_Texture* tex = game->GetTexture("Assets/Laser.png");
	sc->SetTexture(tex);

	mCircleComponent = new CircleComponent(this, 16);
}

void Laser::UpdateActor(float deltaTime) {
	// Asteroid* が要素なのでポインタとして扱う（-> を使う）
	for (auto* asteroid : GetGame()->GetAsteroids()) {
		if (!asteroid) continue;
		CircleComponent* ac = asteroid->GetCircleComponent();
		if (!ac || !mCircleComponent) continue;

		bool isCollidge = mCircleComponent->intersect(ac);
		if (isCollidge) {
			// 衝突したらレーザーと小惑星を削除（削除は保留してループ外で処理すること）
			mState = EDead;
			asteroid->SetState(EDead);
			break;
		}
	}
}

void Laser::InputActor(const Uint8* keyState) {

}