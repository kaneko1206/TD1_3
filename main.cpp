#include <Novice.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "math.h" 

const char kWindowTitle[] = "GC1A_08_カネコショウ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player;
	Enemy* enemy = new Enemy;
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここか
		player->Update(keys);
		enemy->Update();
		float pedx = player->getPosX() - enemy->getPosX();
		float pedy = player->getPosY() - enemy->getPosY();
		float ped = sqrt(pedx * pedx + pedy * pedy);
		if (ped < player->getradius() + enemy->getradius()) {
			player->Oncollision();
		}
		float pbdx = player->getPosX() - enemy->getBulletPosX();
		float pbdy = player->getPosY() - enemy->getBulletPosY();
		float pbd = sqrt(pbdx * pbdx + pbdy * pbdy);
		if (pbd < player->getradius() + enemy->getBulletradius()) {
			player->Oncollision();
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここか
		player->Draw();
		enemy->Draw();

		Novice::ScreenPrintf(50, 50, "d %f", pbd);
		Novice::ScreenPrintf(50, 70, "dx %f", pbdx);
		Novice::ScreenPrintf(50, 90, "dy %f", pbdy);;
		///
		/// ↑描画処理ここまで
		///

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
