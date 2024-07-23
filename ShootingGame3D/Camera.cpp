#include "Camera.h"

void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{

	auto target =VGet((playerpos.x + enemypos.x) / 2, position.y, (playerpos.x + enemypos.x) / 2);
	
	// カメラのクリッピング距離を設定
	SetCameraNearFar(100.0f, 50000.0f);


	//Imguiの実装
}

void Camera::Update(char* input)
{
	const float  CAMERA_LOOK_AT_HEIGHT = 400.0f;
	// カメラの位置と向きを設定
	{
		VECTOR TempPosition1;
		VECTOR TempPosition2;
	
		VECTOR CameraLookAtPosition;

		// 注視点はキャラクターモデルの座標から CAMERA_LOOK_AT_HEIGHT 分だけ高い位置
		CameraLookAtPosition = position;
		CameraLookAtPosition.y += CAMERA_LOOK_AT_HEIGHT;

		// カメラの位置はカメラの水平角度と垂直角度から算出

		
		TempPosition2 = VGet(100, 200, 500);
		
		// 算出した座標に注視点の位置を加算したものがカメラの位置
	     position = VAdd(TempPosition2, CameraLookAtPosition);

		// カメラの設定に反映する
		SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);
	}

}
