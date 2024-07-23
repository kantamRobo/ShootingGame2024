#include "Camera.h"

void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{

	auto target =VGet((playerpos.x + enemypos.x) / 2, position.y, (playerpos.x + enemypos.x) / 2);
	
	// �J�����̃N���b�s���O������ݒ�
	SetCameraNearFar(100.0f, 50000.0f);


	//Imgui�̎���
}

void Camera::Update(char* input)
{
	const float  CAMERA_LOOK_AT_HEIGHT = 400.0f;
	// �J�����̈ʒu�ƌ�����ݒ�
	{
		VECTOR TempPosition1;
		VECTOR TempPosition2;
	
		VECTOR CameraLookAtPosition;

		// �����_�̓L�����N�^�[���f���̍��W���� CAMERA_LOOK_AT_HEIGHT �����������ʒu
		CameraLookAtPosition = position;
		CameraLookAtPosition.y += CAMERA_LOOK_AT_HEIGHT;

		// �J�����̈ʒu�̓J�����̐����p�x�Ɛ����p�x����Z�o

		
		TempPosition2 = VGet(100, 200, 500);
		
		// �Z�o�������W�ɒ����_�̈ʒu�����Z�������̂��J�����̈ʒu
	     position = VAdd(TempPosition2, CameraLookAtPosition);

		// �J�����̐ݒ�ɔ��f����
		SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);
	}

}
