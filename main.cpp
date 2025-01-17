#include <DxLib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <random>

/* メイン */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/* DXライブラリの前処理 */
	// タイトル設定
	SetMainWindowText("DIGITAL CARD GAME");

	// ウィンドウモードに変更
	ChangeWindowMode(TRUE);

	// 画面の拡大率変更を許可
	SetWindowSizeChangeEnableFlag(TRUE);

	// 画面の解像度設定
	SetGraphMode(1920, 1080, 32);

	/* DXライブラリの初期化 */
	if (DxLib_Init() == -1) return -1;

	/* DXライブラリの後処理 */

	// 描画先を裏画面へ
	SetDrawScreen(DX_SCREEN_BACK);


	/* メインループ */
	while (1)
	{

		/* 初期化 */

		// 画面のクリア
		ClearDrawScreen();

		/* 後処理 */

		// 裏画面の描画内容を表画面に反映
		ScreenFlip();

		// Windows システムからくる情報を処理する
		if (ProcessMessage() == -1) break;

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
	}

	/* 後処理 */

	// 終了
	DxLib_End();

	return 0;
}