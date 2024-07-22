#include <DxLib.h>
#include "ObjectAdmin3D.h"
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <d3d11.h>
int Process(char key[256])
{
	if (ScreenFlip() != 0)return false;//�\��ʂƗ���ʂ����ւ���
	if (ProcessMessage() != 0)return false;//���b�Z�[�W�̎�������
	if (ClearDrawScreen() != 0)return false;//�`�悵�Ă����ʂ���������
	if (GetHitKeyStateAll(key) != 0)return false;//�L�[�{�[�h�̓��͂�����

	return true;

	//false�Ȃ烋�[�v���甲����B


}
int main()
{
	char key[256];
	ObjectAdmin3D objectadmin3D;
	ChangeWindowMode(true);//true�ɂ���ƃE�C���h�E��\������
	SetGraphMode(640, 480, 16);//(���̒����A�c�̒����A�J���[�r�b�g�j

	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawMode(DX_DRAWMODE_BILINEAR);

	if (DxLib_Init() == -1)    // �c�w���C�u��������������
	{
		return -1;    // �G���[���N�����璼���ɏI��
	}
	
	ImGui::CreateContext();

	ImGui_ImplWin32_Init(DxLib::GetMainWindowHandle());

	
		auto d = static_cast<ID3D11Device*>(const_cast<void*>(GetUseDirect3D11Device()));
		auto dc = static_cast<ID3D11DeviceContext*>(const_cast<void*>(GetUseDirect3D11DeviceContext()));
		return ImGui_ImplDX11_Init(d, dc);
	

	objectadmin3D.Init3D();
	while (Process(key)) {//���C�����[�v
	
		ImGui_ImplDX11_NewFrame();
		objectadmin3D.Update3D(key);
		// �L�[�̓��͑҂�
		WaitKey();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		{
			ImGui::Begin("Test Window");
			ImGui::End();
			// ImGui�֘A�̕`�揈��
			ImGui::EndFrame();
			ImGui::Render();
			ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

			ScreenFlip();
		}
	}

	// �c�w���C�u�����̌�n��
	DxLib_End();
	return 0;
}