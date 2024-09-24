
#include "Camera.h"
#include <math.h>
void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{
	const float CAMERA_LOOK_AT_HEIGHT = 400.0f;

	CameraLookAtPosition = VGet(190, 2660, -285.000000);
	position = VGet(225, 1930, -1000);
	temppos = position;
}

void Camera::Update(char* input, VECTOR targetpos)
{

	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	//マウスの動きを基準に動く

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
	auto mouseX_F = movetempx * 0.001;
	auto mouseY_F = movetempy * 0.001;


	 moveX = 2000 * sin(mouseX_F) * cos(mouseY_F);
	 moveY = 2000 * sin(mouseY_F); // Y軸方向の移動
	 moveZ = 2000 * cos(mouseX_F) * cos(mouseY_F);
	

	auto debug = temppos;

	temppos = VGet(targetpos.x + moveX, targetpos.y + moveY, targetpos.z + moveZ);
	position = temppos;
	CameraLookAtPosition = targetpos;


	UpdateDirection();

	// カメラの設定に反映する
	SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);



	


}

void Camera::UpdateDirection()
{
	DrawFormatString(320, 250, GetColor(0, 255, 0), L"movetempy %f ", movetempy);
	DrawFormatString(320, 270, GetColor(0, 255, 0), L"movetempx %f ", movetempx);
	forward = VGet(
		cos(movetempy) * sin(movetempx),
		sin(movetempy),
		cos(movetempy) * cos(movetempx)
	);

	right = VGet(
		cos(movetempx),
		0.0f,
		-sin(movetempx)
	);
	
		
		//Camera_FORWARD = VGet(View.m[2][0], View.m[2][1], View.m[2][2]);
		//Camera_Right = VGet(View.m[0][0], View.m[0][1], View.m[0][2]);

}
