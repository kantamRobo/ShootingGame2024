#include "ObjectAdmin.h"
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
   
    ChangeWindowMode(true);//true�ɂ���ƃE�C���h�E��\������
    SetGraphMode(640, 480, 16);//(���̒����A�c�̒����A�J���[�r�b�g�j
  
    SetDrawScreen(DX_SCREEN_BACK);
    SetDrawMode(DX_DRAWMODE_BILINEAR);
    
    if (DxLib_Init() == -1)    // �c�w���C�u��������������
    {
        return -1;    // �G���[���N�����璼���ɏI��
    }

	ObjectAdmin objectAdmin;
	objectAdmin.Init();
	while (Process(key)) {//���C�����[�v
		objectAdmin.judge();
		objectAdmin.Update(key);
		objectAdmin.Draw();
		
	}

  
	return 0;
}