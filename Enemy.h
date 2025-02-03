#pragma once
#include "Object.h"

class Enemy :public Object {
public:
	Enemy(int isAlive, const Vector2 &pos, const Vector2 &velocity, const Vector2 &acceleration, const Vector2 &radius, unsigned int color);

	void Move();

	static void Draw();

	Vector2 GetPos() { return pos_; };
	Vector2 GetRadius() { return radius_; };
	int GetIsAlive() { return isAlive_; };

	void SetIsAlive(int isAlive);

private:
	static std::vector<Enemy *> enemies_;
};
