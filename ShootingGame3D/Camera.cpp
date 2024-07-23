#include "Camera.h"

void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{
	const float  CAMERA_LOOK_AT_HEIGHT = 400.0f;
	
	CameraLookAtPosition.y += CAMERA_LOOK_AT_HEIGHT;

	position = VGet(0, 0, 0);
	temppos = VGet(0, 0, 0);
	//Imguiの実装
}

void Camera::Update(char* input)
{

	


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
	
	auto debug = temppos;
	//TODO: カメラを手動で回転させてオブジェクトのほうを向かせる
	CameraLookAtPosition = position;
	{
	
		position = temppos;

	
		
		// カメラの設定に反映する
		SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);
	}

}
