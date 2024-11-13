#pragma once

#include <DxLib.h>
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
	VECTOR rotation;
	void Init(const VECTOR& playerpos, const VECTOR& enemypos);
	void Update(char* input, VECTOR targetpos);
	void UpdateDirection(float in_x, float in_y);

	void Update_New();
	
	int movetempx = 180;
	int movetempy = 180;
	
	float moveX = 0;
	float moveY = 0;
	float  moveZ = 0;



	


	VECTOR position; //Imguiで調整

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

	void SetForward(const VECTOR& in)
	{
		forward = in;
	}

	void SetRight(const VECTOR& in)
	{
		right = in;
	}
	private:
		VECTOR forward;
		VECTOR right;
private:
	// カメラの向きを更新する (例えば回転行列を使って計算する)
	
};