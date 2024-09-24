#pragma once

#include <DxLib.h>
#include "VECTORUTIL.h"
class Camera {

public:
	Camera()
	{
		movetempx = 0;
		movetempy = 0;
		forward = VGet(0.0f, 0.0f, 1.0f);
		right = VGet(1.0f, 0.0f, 0.0f);
	}
	MATRIX View;
	MATRIX Projection;
	MATRIX Modelmat;
	VECTOR rotation;
	void Init(const VECTOR& playerpos, const VECTOR& enemypos);
	void Update(char* input, VECTOR targetpos);
	void UpdateDirection();
	int movetempx = 0;
	int movetempy = 0;
	
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