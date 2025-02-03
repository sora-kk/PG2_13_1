#pragma once
#include "Object.h"
#include "Bullet.h"

class Player :public Object {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="isAlive"> 生存フラグ </param>
	/// <param name="pos"> 初期座標 </param>
	/// <param name="velocity"> 速度 </param>
	/// <param name="acceleration"> 加速度 </param>
	/// <param name="radius"> 半径 </param>
	/// <param name="color"> 矩形の色 </param>
	Player(int isAlive, const Vector2 &pos, const Vector2 &velocity, const Vector2 &acceleration, const Vector2 &radius, unsigned int color);

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="keys"> キーの入力情報を受け取る箱 </param>
	/// <param name="preKeys"> 1フレーム前のキーの入力情報を受け取る箱 </param>
	void Update(const char keys[], const char preKeys[]);

	/// <summary>
	/// 移動処理
	/// </summary>
	/// <param name="keys"> キーの入力情報を受け取る箱 </param>
	void Move(const char keys[]);

	/// <summary>
	/// 発射処理
	/// </summary>
	/// <param name="keys"> キーの入力情報を受け取る箱 </param>
	void Shoot(const char keys[]);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	std::vector<Bullet> bullets_;

private:
	int shootCoolTime_;
};
