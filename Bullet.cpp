#include "Bullet.h"

Bullet::Bullet(int isAlive, const Vector2 &pos, const Vector2 &velocity, const Vector2 &acceleration, const Vector2 &radius, unsigned int color) {
	isAlive_ = isAlive;
	pos_ = pos;
	velocity_ = velocity;
	acceleration_ = acceleration;
	radius_ = radius;
	color_ = color;
}

void Bullet::Move() {
	pos_.y -= velocity_.y;
}

void Bullet::Draw() const{
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_.x),
		static_cast<int>(radius_.y),
		0.0f, color_, kFillModeSolid
	);
}
