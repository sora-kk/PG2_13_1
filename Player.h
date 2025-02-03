#pragma once
#include "Object.h"
#include "Bullet.h"

class Player :public Object {
public:
	Player(int isAlive, const Vector2 &pos, const Vector2 &velocity, const Vector2 &acceleration, const Vector2 &radius, unsigned int color);

	void Update(const char keys[], const char preKeys[]);

	void Move(const char keys[]);

	void Shoot(const char keys[]);

	void Draw();

	std::vector<Bullet> bullets_;

private:
	int shootCoolTime_;
};
