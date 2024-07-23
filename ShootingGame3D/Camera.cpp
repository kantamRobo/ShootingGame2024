#include "Camera.h"

void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{
	
	
	//Imguiの実装
}

void Camera::Update(char* input)
{

	// カメラの位置と向きを設定
	
	{
		const float  CAMERA_LOOK_AT_HEIGHT = 400.0f;
		// カメラのクリッピング距離を設定
		SetCameraNearFar(100.0f, 10000.0f);
		VECTOR CameraLookAtPosition;
		CameraLookAtPosition.y = CAMERA_LOOK_AT_HEIGHT;

		VECTOR TempPosition1;




		// 注視点はキャラクターモデルの座標から CAMERA_LOOK_AT_HEIGHT 分だけ高い位置
		CameraLookAtPosition = position;

		// カメラの位置はカメラの水平角度と垂直角度から算出
		VECTOR TempPosition2;
		TempPosition2 = VGet(200, 200, 500);

		// 算出した座標に注視点の位置を加算したものがカメラの位置
		position = VAdd(TempPosition2, CameraLookAtPosition);

	
		
		// カメラの設定に反映する
		SetCameraPositionAndTarget_UpVecY(position,VGet(position.x,position.y,400.0f));
	}

}
