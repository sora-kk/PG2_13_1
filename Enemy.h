#pragma once
#include "Object.h"

class Enemy :public Object {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos"> 初期座標 </param>
	/// <param name="velocity"> 速度 </param>
	/// <param name="acceleration"> 加速度 </param>
	/// <param name="radius"> 半径 </param>
	/// <param name="color"> 矩形の色 </param>
	Enemy(const Vector2 &pos, const Vector2 &velocity, const Vector2 &acceleration, const Vector2 &radius, unsigned int color);

	/// <summary>
	/// 移動処理
	/// </summary>
	void Move();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	// ゲッター
	Vector2 GetPos() { return pos_; };
	Vector2 GetRadius() { return radius_; };
	int GetIsAlive() { return isAlive_; };

	void SetIsAlive(int isAlive);

private:
	static int isAlive_;
};
