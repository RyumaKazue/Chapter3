#include "CircleComponent.h"
#include "Actor.h"

CircleComponent::CircleComponent(class Actor* actor, float radius)
	:Component(actor, 100)
	, mRadius(radius) {

}

Vector2 CircleComponent::GetCenter() const {
	return mActor->GetPosition();
}

bool CircleComponent::intersect(const CircleComponent* other) const {
	float distanceSq = GetCenter().LengthSq(other->GetCenter());

	float radiusSum = mRadius + other->mRadius;
	float radiusSumSq = radiusSum * radiusSum;


	return distanceSq < radiusSumSq;
}

