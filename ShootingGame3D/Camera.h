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
	void Update(char* input);
	
	//��{�͌Œ�J�����Ƃ��Ďg���B

	float camrot = -5.67999601;


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
	const VECTOR Camera_Right = right;
	const VECTOR Camera_FORWARD = forward;
	
};