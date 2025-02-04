#include "Enemy.h"

// コンストラクタ
Enemy::Enemy(int isAlive, const Vector2 &pos, const Vector2 &velocity, const Vector2 &acceleration, const Vector2 &radius, unsigned int color) {
	isAlive_ = isAlive;
	pos_ = pos;
	velocity_ = velocity;
	acceleration_ = acceleration;
	radius_ = radius;
	color_ = color;

	enemies_.push_back(this);
}

// 移動処理
void Enemy::Move() {
	if (isAlive_) {
		pos_.x += velocity_.x;
		// 画面端に行ったら方向を反転
		if (pos_.x <= radius_.x || pos_.x >= 1280.0f - radius_.x) {
			velocity_.x *= -1.0f;
		}
	}
}

// 死亡処理
void Enemy::Defeat() {
	isAlive_ = false;
}

// リスポーン処理
void Enemy::Respawn(){
	isAlive_ = true;
}

// 描画処理
void Enemy::Draw() {
	for (Enemy *enemy : enemies_) {
		if (enemy->isAlive_) {
			Novice::DrawEllipse(
				static_cast<int>(enemy->pos_.x),
				static_cast<int>(enemy->pos_.y),
				static_cast<int>(enemy->radius_.x),
				static_cast<int>(enemy->radius_.y),
				0.0f, enemy->color_, kFillModeSolid
			);
		}
	}
}