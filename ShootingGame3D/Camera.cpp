#include "Camera.h"

void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{
	
	
	//Imgui�̎���
}

void Camera::Update(char* input)
{

	// �J�����̈ʒu�ƌ�����ݒ�
	
	{
		const float  CAMERA_LOOK_AT_HEIGHT = 400.0f;
		// �J�����̃N���b�s���O������ݒ�
		SetCameraNearFar(100.0f, 10000.0f);
		VECTOR TempPosition1;




		// �����_�̓L�����N�^�[���f���̍��W���� CAMERA_LOOK_AT_HEIGHT �����������ʒu
		
		
		VECTOR TempPosition2;
		TempPosition2 = VGet(200, 200, 500);
		//TempPosiiton2�̈ʒu���t���[�����Ƃɉ��Z����Ă���̂ŁA�����̎Z�o��݌v����
		// �Z�o�������W�ɒ����_�̈ʒu�����Z�������̂��J�����̈ʒu
		VECTOR CameraLookAtPosition;
		CameraLookAtPosition.y = CAMERA_LOOK_AT_HEIGHT;
		CameraLookAtPosition = position;


		position = VAdd(TempPosition2, CameraLookAtPosition);

	
		
		// �J�����̐ݒ�ɔ��f����
		SetCameraPositionAndTarget_UpVecY(position,VGet(position.x,position.y,400.0f));
	}

}
