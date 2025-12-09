#pragma once

class Vector2 {
public:
	float x;
	float y;

	Vector2();
	Vector2(float _x, float _y);

	Vector2 operator+(const Vector2 vec) const { return Vector2(x + vec.x, y + vec.y); };
	Vector2 operator*(const float scalar) const { return Vector2(x * scalar, y * scalar); };
};