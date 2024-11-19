#include "ICamera.h"
#include "Camera.h"
#include <math.h>
void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{
	const float CAMERA_LOOK_AT_HEIGHT = 400.0f;
	// �J�����̑O���x�N�g���̋t�����ɔz�u������
	float distance = 30.0f;  // �v���C���[����J�����܂ł̋���
	VECTOR forwardInverse = VScale(GetCameraForward(), -distance);  // �O���x�N�g���̋t����

	
	position = VAdd(playerpos, forwardInverse);//TODO:�v���C���[�̑O���x�N�g�����擾
	temppos = position;
	// �J�����̐ݒ�ɔ��f����
	SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);

}

void Camera::Update(char* input, VECTOR targetpos)
{

	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	//�}�E�X�̓�������ɓ���

	if (input[KEY_INPUT_A] == 1)
	{
		movetempx -= 10;
	}

	if (input[KEY_INPUT_D] == 1)
	{
		movetempx += 10;
	}

	if (input[KEY_INPUT_W] == 1)
	{
		movetempy -= 10;
	}

	if (input[KEY_INPUT_S] == 1)
	{
		movetempy += 10;
	}
	
	float yaw = movetempx * 0.001f;  // Yaw (������])
	float pitch = movetempy * 0.001f;  // Pitch (�㉺��])
	// �J�����̌��� (�����x�N�g��) ���X�V
	UpdateDirection(yaw, pitch);
	 moveX = 2000 * sin(yaw) * cos(pitch);
	 moveY = 2000 * sin(pitch); // Y�������̈ړ�
	 moveZ = 2000 * cos(yaw) * cos(yaw);
	

	auto debug = temppos;

	temppos = VGet(targetpos.x + moveX, targetpos.y + moveY, targetpos.z + moveZ);
	position = temppos;
	CameraLookAtPosition = targetpos;


	

	

	View = GetCameraViewMatrix();
	
	forward=Set(VGet(MInverse(View).m[2][0], MInverse(View).m[2][1], MInverse(View).m[2][2]));
	right=Set(VGet(MInverse(View).m[0][0], MInverse(View).m[0][1], MInverse(View).m[0][2]));
	up = VCross(right, forward);

	// �J�����̐ݒ�ɔ��f����
	SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);
}

void Camera::UpdateDirection(float yaw, float pitch)
{
	
	// �s�b�`�i�㉺�j�͈̔͂𐧌��i�Ⴆ�� -90�x����90�x�͈͓̔��ɂ���j
	const float pitchLimit = DX_PI_F / 2.0f - 0.01f;  // �s�b�`�̐���
	if (pitch > pitchLimit) pitch = pitchLimit;
	if (pitch < -pitchLimit) pitch = -pitchLimit;
	

	

	
	{



	}


	right = VNorm(VCross(up, forward));   // �O�����x�N�g���Ə�����x�N�g������E�����x�N�g�����v�Z

	
	
	// �f�o�b�O�p�\��
	DrawFormatString(100, 80, GetColor(0, 255, 0), L"pitch=%f",  pitch);
	DrawFormatString(100, 100, GetColor(0, 255, 0), L"Yaw: x = % f", yaw);

	DrawFormatString(100, 120, GetColor(0, 255, 0), L"�J�����O���x�N�g��: x=%f, y=%f, z=%f", forward.x, forward.y, forward.z);
	DrawFormatString(100, 140, GetColor(0, 255, 0), L"�J�����E���x�N�g��: x=%f, y=%f, z=%f", right.x, right.y, right.z);
}

void Camera::Update_New()
{
	//�r���[�s��̈ʒu���Z�o
	auto eye = VSub(CameraLookAtPosition, this->position);
	CreateLookAtMatrix(&LookAt,&eye,&CameraLookAtPosition,&up);

	//�r���[�v���W�F�N�V�����s��̍쐬
	CreatePerspectiveFovMatrix(&View, 1.0f, 1.0f, 10000.0f);

	//�r���[�v���W�F�N�V�����s��̋t�s����v�Z
	MInverse(MMult(View,Projection));

	//�v���W�F�N�V�����s��̋t�s����v�Z
	MInverse(Projection);


	
}
