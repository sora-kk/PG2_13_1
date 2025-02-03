#pragma once
#include <math.h>
#include "Vector2.h"

class IsHit {
public:
	int Judge(const Vector2 &pos1, float radius1, const Vector2 &pos2, float radius2);
};
