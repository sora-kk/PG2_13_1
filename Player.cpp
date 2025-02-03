#include "Player.h"

Player::Player(int isAlive, const Vector2 &pos, const Vector2 &velocity, const Vector2 &acceleration, const Vector2 &radius, unsigned int color) {
	isAlive_ = isAlive;
	pos_ = pos;
	velocity_ = velocity;
	acceleration_ = acceleration;
	radius_ = radius;
	color_ = color;
	shootCoolTime_ = 1;
}

void Player::Update(const char keys[], const char preKeys[]) {
	if (keys == nullptr || preKeys == nullptr) {
		return;
	}

	Move(keys);

	Shoot(keys);
}

void Player::Move(const char keys[]) {
	if (keys[DIK_W]) {
		pos_.y -= velocity_.y;
	} else if (keys[DIK_S]) {
		pos_.y += velocity_.y;
	}

	if (keys[DIK_A]) {
		pos_.x -= velocity_.x;
	} else if (keys[DIK_D]) {
		pos_.x += velocity_.x;
	}
}

void Player::Shoot(const char keys[]) {
	if (keys[DIK_SPACE]) {
		if (shootCoolTime_ > 0) {
			shootCoolTime_--;
		} else {
			shootCoolTime_ = 8;
		}
	}

	if (shootCoolTime_ <= 0) {
		Bullet bullet(
			true,
			pos_,
			Vector2{ 8.0f,8.0f },
			Vector2{ 0.0f,0.0f },
			Vector2{ 8.0f,8.0f },
			WHITE
		);
		bullets_.push_back(bullet);
	}

	for (auto it = bullets_.begin(); it != bullets_.end();) {
		it->Move();
		if (it->GetPos().y < 0.0f) {
			it = bullets_.erase(it);
		} else {
			it++;
		}
	}
}

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
