#include "Player.h"

// コンストラクタ
Player::Player(const Vector2 &pos, const Vector2 &velocity, const Vector2 &acceleration, const Vector2 &radius, unsigned int color) {
	pos_ = pos;
	velocity_ = velocity;
	acceleration_ = acceleration;
	radius_ = radius;
	color_ = color;
	shootCoolTime_ = 1;
}

// 更新処理
void Player::Update(const char keys[], const char preKeys[]) {
	if (keys == nullptr || preKeys == nullptr) {
		return;
	}

	// 移動
	Move(keys);

	// 弾を発射
	Shoot(keys);
}

// 移動処理
void Player::Move(const char keys[]) {
	// 縦移動
	if (keys[DIK_W]) {
		pos_.y -= velocity_.y;
	} else if (keys[DIK_S]) {
		pos_.y += velocity_.y;
	}

	// 横移動
	if (keys[DIK_A]) {
		pos_.x -= velocity_.x;
	} else if (keys[DIK_D]) {
		pos_.x += velocity_.x;
	}
}

// 発射処理
void Player::Shoot(const char keys[]) {
	// クールタイムをカウント
	if (keys[DIK_SPACE]) {
		if (shootCoolTime_ > 0) {
			shootCoolTime_--;
		} else {
			shootCoolTime_ = 8;
		}
	}

	// クールタイムが0になると弾を発射
	if (shootCoolTime_ <= 0) {
		Bullet bullet(
			pos_,
			Vector2{ 8.0f,8.0f },
			Vector2{ 0.0f,0.0f },
			Vector2{ 8.0f,8.0f },
			WHITE
		);
		bullets_.push_back(bullet);
	}

	// 弾の更新処理
	for (auto it = bullets_.begin(); it != bullets_.end();) {
		it->Move();

		// 画面外にいった弾を削除
		if (it->GetPos().y < 0.0f) {
			it = bullets_.erase(it);
		} else {
			it++;
		}
	}
}

// 描画処理
void Player::Draw() {
	Novice::DrawBox(
		static_cast<int>(pos_.x - radius_.x),
		static_cast<int>(pos_.y - radius_.y),
		static_cast<int>(radius_.x * 2.0f),
		static_cast<int>(radius_.y * 2.0f),
		0.0f, color_, kFillModeSolid
	);

	for (const auto &bullet : bullets_) {
		bullet.Draw();
	}
}
