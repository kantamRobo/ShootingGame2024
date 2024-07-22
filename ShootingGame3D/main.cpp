#include <DxLib.h>
#include "ObjectAdmin3D.h"
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <d3d11.h>
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
	ObjectAdmin3D objectadmin3D;
	ChangeWindowMode(true);//trueにするとウインドウを表示する
	SetGraphMode(640, 480, 16);//(横の長さ、縦の長さ、カラービット）

	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawMode(DX_DRAWMODE_BILINEAR);

	if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
	{
		return -1;    // エラーが起きたら直ちに終了
	}
	
	ImGui::CreateContext();

	ImGui_ImplWin32_Init(DxLib::GetMainWindowHandle());

	
		auto d = static_cast<ID3D11Device*>(const_cast<void*>(GetUseDirect3D11Device()));
		auto dc = static_cast<ID3D11DeviceContext*>(const_cast<void*>(GetUseDirect3D11DeviceContext()));
		return ImGui_ImplDX11_Init(d, dc);
	

	objectadmin3D.Init3D();
	while (Process(key)) {//メインループ
	
		ImGui_ImplDX11_NewFrame();
		objectadmin3D.Update3D(key);
		// キーの入力待ち
		WaitKey();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		{
			ImGui::Begin("Test Window");
			ImGui::End();
			// ImGui関連の描画処理
			ImGui::EndFrame();
			ImGui::Render();
			ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

			ScreenFlip();
		}
	}

	// ＤＸライブラリの後始末
	DxLib_End();
	return 0;
}