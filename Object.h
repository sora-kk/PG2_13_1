#pragma once
#include <Novice.h>
#include <memory>
#include <vector>
#include <Vector2.h>

class Object {
protected:
	Vector2 pos_;
	Vector2 velocity_;
	Vector2 acceleration_;
	Vector2 radius_;
	unsigned int color_;
};
