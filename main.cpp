#include <Novice.h>
#include <memory>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "IsHit.h"

using namespace std;

const char kWindowTitle[] = "LC1C_11_ダイドウソラ_PG2_13_1";

// ローカル変数の宣言と初期化
const float kWinWidth = 1280.0f;
const float kWinHeight = 720.0f;

// 静的メンバ変数の初期化
std::vector<Enemy*> Enemy::enemies_;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(
		kWindowTitle,
		static_cast<int>(kWinWidth),
		static_cast<int>(kWinHeight)
	);

	///====================
	/// ↓ 変数の宣言と初期化
	///====================

	// プレイヤー
	std::unique_ptr<Player> player = std::make_unique<Player>(
		true,
		Vector2{ 600.0f,600.0f },
		Vector2{ 8.0f,8.0f },
		Vector2{ 0.0f,0.0f },
		Vector2{ 16.0f,16.0f },
		WHITE
	);

	// エネミー
	Enemy *enemy1 = new Enemy(
		true,
		Vector2{ 200.0f,200.0f },
		Vector2{ 8.0f,8.0f },
		Vector2{ 0.0f,0.0f },
		Vector2{ 16.0f,16.0f },
		RED
	);

	Enemy *enemy2 = new Enemy(
		true,
		Vector2{ 400.0f,400.0f },
		Vector2{ 8.0f,8.0f },
		Vector2{ 0.0f,0.0f },
		Vector2{ 16.0f,16.0f },
		RED
	);

	// 当たり判定
	std::unique_ptr<IsHit>isHit;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	///====================
	/// ↑ 変数の宣言と初期化
	///====================

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///===================
		/// ↓ 更新処理 ここから
		///===================

		// プレイヤー
		player->Update(keys, preKeys);

		// エネミー
		enemy1->Move();
		enemy2->Move();

		// Rを押すとリスポーン
		if (keys[DIK_R] && !preKeys[DIK_R]) {
			if (!enemy1->GetIsAlive() || !enemy2->GetIsAlive()) {
				enemy1->SetIsAlive(true);
				enemy2->SetIsAlive(true);
			}
		}

		// 当たり判定
		if (enemy1->GetIsAlive() || enemy2->GetIsAlive()) {
			for (auto it = player->bullets_.begin(); it != player->bullets_.end();) {
				if (isHit->Judge(it->GetPos(), it->GetRadius().x, enemy1->GetPos(), enemy1->GetRadius().x) ||
					isHit->Judge(it->GetPos(), it->GetRadius().x, enemy2->GetPos(), enemy2->GetRadius().x)) {
					it = player->bullets_.erase(it);
					enemy1->SetIsAlive(false);
					enemy2->SetIsAlive(false);
				} else {
					it++;
				}
			}
		}

		///===================
		/// ↑ 更新処理 ここまで
		///===================

		///===================
		/// ↓ 描画処理 ここから
		///===================

		// プレイヤー
		player->Draw();

		// エネミー
		Enemy::Draw();

		///===================
		/// ↑ 描画処理 ここまで
		///===================

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
