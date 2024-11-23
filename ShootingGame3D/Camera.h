#pragma once
#include "Quaternion.h"

#include "VECTORUTIL.h"

class Camera{

public:
	Camera()
	{
		movetempx = 180;
		movetempy = 180;
		forward = VGet(0.0f, 0.0f, 1.0f);
		right = VGet(1.0f, 0.0f, 0.0f);
		const float CAMERA_LOOK_AT_HEIGHT = 400.0f;

		CameraLookAtPosition = VGet(0, 0, 0);
		position = VGet(0, 0, 0);
		temppos = position;
	}
	MATRIX View;
	MATRIX Projection;
	MATRIX Modelmat;
	MATRIX LookAt;
	MATRIX rotation;
	void Init(const VECTOR& playerpos, const VECTOR& enemypos);
	void Update(char* input, VECTOR targetpos);
	void UpdateDirection(float in_x, float in_y);
	Quaternion camquat;
	
	int movetempx = 180;
	int movetempy = 180;
	
	float moveX = 0;
	float moveY = 0;
	float  moveZ = 0;



	


	VECTOR position; //Imgui�Œ���

	VECTOR target;

	VECTOR CameraLookAtPosition;

	VECTOR temppos =VGet(0,0,0);

	MATRIX GetViewMatrix() {
		return GetCameraViewMatrix();
	}

public:


	VECTOR GetCameraRight() {
		return right;
	}
	VECTOR GetCameraForward() {
		return forward;
	}

	VECTOR GetCameraUp() {
		return up;
	}

	void SetForward(const VECTOR& in)
	{
		forward = in;
	}

	void SetRight(const VECTOR& in)
	{
		right = in;
	}
	private:
		VECTOR forward= VNorm(VGet(0,0,1));//z�̓O���[�o�����W�A12�������𐳖ʂƂ���ƌ������ɂȂ�̂Ń}�C�i�X�ɂ��Ĕ��]�����Ȃ��Ƃ����Ȃ�
		VECTOR right= VNorm(VGet(1,0,0));
		VECTOR  up = VNorm(VGet(0, 1, 0));     // �����
		//�P�ɃO���[�o�����W�n���L�q���邾������Ӗ����Ȃ��B�J�����̍��W�n���g���Čv�Z����K�v������B
private:
	
	
};