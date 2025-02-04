#include "Bullet.h"

// コンストラクタ
Bullet::Bullet(const Vector2 &pos, const Vector2 &velocity, const Vector2 &acceleration, const Vector2 &radius, unsigned int color) {
	pos_ = pos;
	velocity_ = velocity;
	acceleration_ = acceleration;
	radius_ = radius;
	color_ = color;
}

// 移動処理
void Bullet::Move() {
	pos_.y -= velocity_.y;
}

// 描画処理
void Bullet::Draw() const{
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_.x),
		static_cast<int>(radius_.y),
		0.0f, color_, kFillModeSolid
	);
}
