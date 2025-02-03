#pragma once
#include <math.h>
#include "Vector2.h"

class IsHit {
public:
	/// <summary>
	/// 当たり判定
	/// </summary>
	/// <param name="pos1"> 判定の対象1の座標 </param>
	/// <param name="radius1"> 判定の対象1の半径 </param>
	/// <param name="pos2"> 判定の対象2の座標 </param>
	/// <param name="radius2"> 判定の対象2の半径 </param>
	/// <returns> 当たっていたらtrue,違ったらfalse </returns>
	int Judge(const Vector2 &pos1, float radius1, const Vector2 &pos2, float radius2);
};
