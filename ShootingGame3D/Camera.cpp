#include "Camera.h"

void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{
	const float  CAMERA_LOOK_AT_HEIGHT = 400.0f;
	
	CameraLookAtPosition.y += CAMERA_LOOK_AT_HEIGHT;

	position = VGet(0, 0, 0);
	//Imguiの実装
}

void Camera::Update(char* input)
{

	//TODO: カメラを手動で回転させてオブジェクトのほうを向かせる
	CameraLookAtPosition = position;
	{
	
		position.x += 20;

	
		
		// カメラの設定に反映する
		SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);
	}

}
