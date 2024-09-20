#pragma once

#include <DxLib.h>
#include "VECTORUTIL.h"
class Camera {

public:
	
	MATRIX View;
	MATRIX Projection;
	MATRIX Modelmat;
	VECTOR rotation;
	void Init(const VECTOR& playerpos, const VECTOR& enemypos);
	void Update(char* input, VECTOR targetpos);
	int movetempx = 0;
	int movetempy = 0;
	
	//��{�͌Œ�J�����Ƃ��Ďg���B

	


	VECTOR position; //Imgui�Œ���

	VECTOR target;

	VECTOR CameraLookAtPosition;

	VECTOR temppos =VGet(0,0,0);

	MATRIX GetViewMatrix() {
		return GetCameraViewMatrix();
	}

public:


	VECTOR GetCameraRight() {
		return Camera_Right;
	}
	VECTOR GetCameraForward() {
		return Camera_FORWARD;
	}
	private:
	 VECTOR Camera_Right = right;
	 VECTOR Camera_FORWARD = forward;
	
private:
	// �J�����̌������X�V���� (�Ⴆ�Ή�]�s����g���Čv�Z����)
	void UpdateDirection(float angleX, float angleY);
};