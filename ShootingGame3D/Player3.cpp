
#include "RootObject3D.h"
#include "Camera.h"
#include "Player3.h"



void Player3::Draw()
{
}


void Player3::Update(Camera* camera,char* input)
{
	Draw3D(position);
	for (int i = 0; i < MAX_AMMO; i++) {
		ammo[i]->Update(50);
		
	}
	
	sphere.DrawDebug(position);
	
Move(camera,input);
	
	
}


void Player3::PlayerInput(char* input){
	

	if(input[KEY_INPUT_A] == 1) {

	
	
		AttackTrigger();
		
	}
	
	
	
	

}

void Player3::Move(Camera* camera,char* input)
{

	
	
	DrawFormatString(320, 180, GetColor(0, 255, 0), L"前方ベクトルz %f ", camera->GetCameraForward().z);
	DrawFormatString(320, 160, GetColor(0, 255, 0), L"前方ベクトルx %f ", camera->GetCameraForward().x);
	DrawFormatString(320, 200, GetColor(0, 255, 0), L"右ベクトルx %f ", camera->GetCameraRight().x);
	DrawFormatString(320, 220, GetColor(0, 255, 0), L"右ベクトルz %f ", camera->GetCameraRight().z);
	// forwardとrightの初期化 (Y成分を0にして正規化)
	  // 地面に沿った移動を考慮してY軸を0に
	camera->SetForward(VGet(camera->GetCameraForward().x, 0, camera->GetCameraForward().z));
	camera->SetForward(VNorm(camera->GetCameraForward())); // 正規化

	 
	camera->SetRight(VGet(camera->GetCameraRight().x, 0, camera->GetCameraRight().z));
	camera->SetRight(VNorm(camera->GetCameraRight())); // 正規化

	// 水平方向と垂直方向の移動をリセット
	VECTOR move = VGet(0.0f, 0.0f, 0.0f);
	int move_horizontal = 0;
	int move_vertical = 0;
	// プレイヤーの向きにカメラの向きを反映させる
   // forwardベクトルに基づいてY軸回転角度を計算
	float playerRotationY = atan2(camera->GetCameraForward().z, camera->GetCameraForward().x);
	
	// プレイヤーの回転行列を設定
	MATRIX rotationMatrix = MGetRotY(playerRotationY);
	DrawFormatString(320, 240, GetColor(0, 255, 0), L"PlayerRotation %f ", playerRotationY);
	MV1SetRotationXYZ(handle, VGet(0, playerRotationY, 0));
	// 入力に応じて移動量を設定
	if (input[KEY_INPUT_UP] == 1) {
		move_vertical = 1; // 前進
	}
	if (input[KEY_INPUT_DOWN] == 1) {
		move_vertical = -1; // 後退
	}
	if (input[KEY_INPUT_LEFT] == 1) {
		move_horizontal = -1; // 左移動
	}
	if (input[KEY_INPUT_RIGHT] == 1) {
		move_horizontal = 1; // 右移動
	}

	// カメラ基準での移動ベクトルを計算
	VECTOR moveH = VScale(camera->GetCameraRight(), move_horizontal * 5);  // 右方向に移動
	VECTOR moveV = VScale(camera->GetCameraForward(), move_vertical * 5);  // 前方向に移動

	// 最終的な移動ベクトルを計算
	move = VAdd(moveH, moveV);

	// プレイヤーの位置を更新
	position = VAdd(position, move);
}


