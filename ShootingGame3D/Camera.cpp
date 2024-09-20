
#include "Camera.h"
#include <math.h>
void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{
	const float CAMERA_LOOK_AT_HEIGHT = 400.0f;

	CameraLookAtPosition = VGet(190, 2660, -285.000000);
	position = VGet(225, 1930, -1000);
	temppos = position;
}

void Camera::Update(char* input,VECTOR targetpos)
{
	
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	//�}�E�X�̓�������ɓ���
	
	 
	GetMousePoint(&movetempx, &movetempy);
	auto mouseX_F = movetempx * 0.001;
	auto mouseY_F = movetempy * 0.001;
	
	
	auto moveX = 2000 * sin(mouseX_F) * cos(mouseY_F);
	auto moveY = 2000 * sin(mouseY_F); // Y�������̈ړ�
	auto moveZ = 2000 * cos(mouseX_F) * cos(mouseY_F);


	
	auto debug = temppos;
	
	temppos = VGet(targetpos.x+moveX, targetpos.y+moveY, targetpos.z+moveZ);
		position = temppos;
		CameraLookAtPosition = targetpos;

		//�J�����̌��������肷��

		
		
		// �J�����̐ݒ�ɔ��f����
		SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);
	
	
		/*
		//�J�������A�}�E�X��XY���ŉ�]������
		if (input[mouse] == 1)
		{
		rotation.x+= 0.1;
		}
		if (input[KEY_INPUT_DOWN] == 1)
		{
			rotation.x-= 0.1;
		}
		if (input[KEY_INPUT_LEFT] == 1)
		{
			rotation.y+= 0.1;
		}
		if (input[KEY_INPUT_RIGHT] == 1)
		{
			rotation.y-= 0.1;
		}
		*/
		

}
