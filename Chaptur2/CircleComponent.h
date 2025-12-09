#pragma once
#include "Component.h"
#include "Vector2.h"
class CircleComponent :
    public Component
{
public:
    CircleComponent(class Actor* actor, float radius);
    float GerRadius() const { return mRadius; };
    bool intersect(const CircleComponent* other) const;
    Vector2 GetCenter() const;


private:
    float mRadius;
};

