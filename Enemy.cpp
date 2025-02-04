#include "Enemy.h"

int Enemy::isAlive_ = true;

// コンストラクタ
Enemy::Enemy(const Vector2 &pos, const Vector2 &velocity, const Vector2 &acceleration, const Vector2 &radius, unsigned int color) {
	pos_ = pos;
	velocity_ = velocity;
	acceleration_ = acceleration;
	radius_ = radius;
	color_ = color;
}

// 移動処理
void Enemy::Move() {
	if (Enemy::isAlive_) {
		pos_.x += velocity_.x;
		// 画面端に行ったら方向を反転
		if (pos_.x <= radius_.x || pos_.x >= 1280.0f - radius_.x) {
			velocity_.x *= -1.0f;
		}
	}
}

// 描画処理
void Enemy::Draw() {
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_.x),
		static_cast<int>(radius_.y),
		0.0f, color_, kFillModeSolid
	);
}

void Enemy::SetIsAlive(int isAlive) {
	Enemy::isAlive_ = isAlive;
}
