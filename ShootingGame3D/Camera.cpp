#include "Camera.h"

void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{
	const float  CAMERA_LOOK_AT_HEIGHT = 400.0f;
	
	CameraLookAtPosition.y += CAMERA_LOOK_AT_HEIGHT;

	position = VGet(0, 0, 0);
	//Imgui�̎���
}

void Camera::Update(char* input)
{

	//TODO: �J�������蓮�ŉ�]�����ăI�u�W�F�N�g�̂ق�����������
	CameraLookAtPosition = position;
	{
	
		position.x += 20;

	
		
		// �J�����̐ݒ�ɔ��f����
		SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);
	}

}
