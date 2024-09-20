
#include "Camera.h"

void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{
	const float CAMERA_LOOK_AT_HEIGHT = 400.0f;

	CameraLookAtPosition = VGet(190, 2660, -285.000000);
	position = VGet(225, 1930, -1000);
	temppos = position;
}

void Camera::Update(char* input)
{
	
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	
	auto debug = temppos;
	
	
		position = temppos;
		CameraLookAtPosition = VGet(position.x, position.y, position.z + 1000); // �����_���J�����ʒu�ɑ΂��đO���ɐݒ�

	
		// �J�����̐ݒ�ɔ��f����
		SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);
	
		SetCameraPositionAndAngle(position, camrot,0, 0);

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
