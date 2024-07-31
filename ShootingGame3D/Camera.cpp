#include "Camera.h"

void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{
	const float CAMERA_LOOK_AT_HEIGHT = 400.0f;

	CameraLookAtPosition = VGet(playerpos.x, playerpos.y + CAMERA_LOOK_AT_HEIGHT, playerpos.z);
	position = VGet(0, 0, -1000);  // �J�����̏����ʒu�𒲐�
	temppos = position;
}

void Camera::Update(char* input)
{
	
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);


	if (input[KEY_INPUT_UP] == 1)
	{
		
			temppos.y -= 5;
			
		
	}

	if (input[KEY_INPUT_DOWN] == 1)
	{
		
		temppos.y += 5;
			//posY += 5;
		
	}

	if (input[KEY_INPUT_LEFT] == 1) {
	
		temppos.x -= 5;
		
	}

	if (input[KEY_INPUT_RIGHT] == 1)
	{
		
		temppos.x += 5;

		
	}

	if (input[KEY_INPUT_T] == 1)
	{
		temppos.z += 5;
	}

	if (input[KEY_INPUT_B] == 1)
	{
		temppos.z -= 5;
	}


	
	auto debug = temppos;
	
	
		position = temppos;
		CameraLookAtPosition = VGet(position.x, position.y, position.z + 1000); // �����_���J�����ʒu�ɑ΂��đO���ɐݒ�

	
		x += 0.04;
		
		// �J�����̐ݒ�ɔ��f����
		SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);
	
		SetCameraPositionAndAngle(position, x,0, 0);

		//TODO:x���𑀍삵�Ă��������Ɍ����낵���_�ɂ���
}
