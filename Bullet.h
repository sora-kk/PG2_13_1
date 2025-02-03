#pragma once
#include "Object.h"

class Bullet : public Object {
public:
	Bullet(int isAlive, const Vector2 &pos, const Vector2 &velocity, const Vector2 &acceleration, const Vector2 &radius, unsigned int color);

	void Move();

	void Draw() const;

	Vector2 GetPos() { return pos_; };
	Vector2 GetRadius() { return radius_; };
};
