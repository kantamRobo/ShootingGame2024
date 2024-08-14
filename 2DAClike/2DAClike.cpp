#include "ObjectAdmin2D.h"
#include <DxLib.h>
int Process(char key[256])
{
	if (ScreenFlip() != 0)return false;//表画面と裏画面を入れ替える
	if (ProcessMessage() != 0)return false;//メッセージの自動処理
	if (ClearDrawScreen() != 0)return false;//描画している画面を消去する
	if (GetHitKeyStateAll(key) != 0)return false;//キーボードの入力をする

	return true;

	//falseならループから抜ける。


}
int main()
{
	char key[256];

	ChangeWindowMode(true);//trueにするとウインドウを表示する
	SetGraphMode(640, 480, 16);//(横の長さ、縦の長さ、カラービット）

	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawMode(DX_DRAWMODE_BILINEAR);

	if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
	{
		return -1;    // エラーが起きたら直ちに終了
	}

	ObjectAdmin2D objectAdmin;
	objectAdmin.Init2D();
	while (Process(key)) {//メインループ
		objectAdmin.judge();
		objectAdmin.Update2D(key);


	}


	return 0;
}