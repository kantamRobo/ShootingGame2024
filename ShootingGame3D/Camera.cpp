#include "ICamera.h"
#include "Camera.h"
#include <math.h>
void Camera::Init(const VECTOR& playerpos,const VECTOR& enemypos)
{
	const float CAMERA_LOOK_AT_HEIGHT = 400.0f;
	// カメラの前方ベクトルの逆方向に配置したい
	float distance = 30.0f;  // プレイヤーからカメラまでの距離
	VECTOR forwardInverse = VScale(GetCameraForward(), -distance);  // 前方ベクトルの逆方向

	
	position = VAdd(playerpos, forwardInverse);//TODO:プレイヤーの前方ベクトルを取得
	temppos = position;
	// カメラの設定に反映する
	SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);

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
	
	float yaw = movetempx * 0.001f;  // Yaw (水平回転)
	float pitch = movetempy * 0.001f;  // Pitch (上下回転)
	// カメラの向き (方向ベクトル) を更新
	UpdateDirection(yaw, pitch);
	 moveX = 2000 * sin(yaw) * cos(pitch);
	 moveY = 2000 * sin(pitch); // Y軸方向の移動
	 moveZ = 2000 * cos(yaw) * cos(yaw);
	

	auto debug = temppos;

	temppos = VGet(targetpos.x + moveX, targetpos.y + moveY, targetpos.z + moveZ);
	position = temppos;
	CameraLookAtPosition = targetpos;


	

	

	View = GetCameraViewMatrix();
	
	forward=Set(VGet(MInverse(View).m[2][0], MInverse(View).m[2][1], MInverse(View).m[2][2]));
	right=Set(VGet(MInverse(View).m[0][0], MInverse(View).m[0][1], MInverse(View).m[0][2]));
	up = VCross(right, forward);

	// カメラの設定に反映する
	SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);
}

void Camera::UpdateDirection(float yaw, float pitch)
{
	
	// ピッチ（上下）の範囲を制限（例えば -90度から90度の範囲内にする）
	const float pitchLimit = DX_PI_F / 2.0f - 0.01f;  // ピッチの制限
	if (pitch > pitchLimit) pitch = pitchLimit;
	if (pitch < -pitchLimit) pitch = -pitchLimit;
	

	

	
	{



	}


	right = VNorm(VCross(up, forward));   // 前方向ベクトルと上方向ベクトルから右方向ベクトルを計算

	
	
	// デバッグ用表示
	DrawFormatString(100, 80, GetColor(0, 255, 0), L"pitch=%f",  pitch);
	DrawFormatString(100, 100, GetColor(0, 255, 0), L"Yaw: x = % f", yaw);

	DrawFormatString(100, 120, GetColor(0, 255, 0), L"カメラ前方ベクトル: x=%f, y=%f, z=%f", forward.x, forward.y, forward.z);
	DrawFormatString(100, 140, GetColor(0, 255, 0), L"カメラ右方ベクトル: x=%f, y=%f, z=%f", right.x, right.y, right.z);
}

void Camera::Update_New()
{
	//ビュー行列の位置を算出
	auto eye = VSub(CameraLookAtPosition, this->position);
	CreateLookAtMatrix(&LookAt,&eye,&CameraLookAtPosition,&up);

	//ビュープロジェクション行列の作成
	CreatePerspectiveFovMatrix(&View, 1.0f, 1.0f, 10000.0f);

	//ビュープロジェクション行列の逆行列を計算
	MInverse(MMult(View,Projection));

	//プロジェクション行列の逆行列を計算
	MInverse(Projection);


	
}
