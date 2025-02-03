#include "IsHit.h"

int IsHit::Judge(const Vector2 &pos1, float radius1, const Vector2 &pos2, float radius2){
	Vector2 pos_ = { pos1.x - pos2.x,pos1.y - pos2.y };
	float length_ = sqrtf(pos_.x * pos_.x + pos_.y * pos_.y);
	if (length_ <= radius1 + radius2) {
		return true;
	} else {
		return false;
	}
}
