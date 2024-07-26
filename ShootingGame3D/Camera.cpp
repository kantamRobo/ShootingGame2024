#include "Camera.h"

void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{
	const float CAMERA_LOOK_AT_HEIGHT = 400.0f;

	CameraLookAtPosition = VGet(playerpos.x, playerpos.y + CAMERA_LOOK_AT_HEIGHT, playerpos.z);
	position = VGet(0, 0, -1000);  // カメラの初期位置を調整
	temppos = position;
}

void Camera::Update(char* input)
{

	

/*
	if (input[KEY_INPUT_UP] == 1)
	{
		
			temppos.y -= 5;
			
		
	}

	if (input[KEY_INPUT_DOWN] == 1)
	{
		
		temppos.y += 5;
			//posY += 5;
		
	}

	if (input[KEY_INPUT_LEFT] == 1) {
	
		temppos.x -= 5;
		
	}

	if (input[KEY_INPUT_RIGHT] == 1)
	{
		
		temppos.x += 5;

		
	}
	*/
	auto debug = temppos;
	//TODO: カメラを手動で回転させてオブジェクトのほうを向かせる
	
	
		position = temppos;
		CameraLookAtPosition = VGet(position.x, position.y, position.z + 1000); // 注視点をカメラ位置に対して前方に設定

	
		
		// カメラの設定に反映する
		SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);
	

}
