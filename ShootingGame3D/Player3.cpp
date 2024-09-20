#include "Camera.h"
#include "RootObject3D.h"

#include "Player3.h"



void Player3::Draw()
{
}

void Player3::Update()
{
	
}

void Player3::Update(char* input)
{
	Draw3D(position);
	for (int i = 0; i < MAX_AMMO; i++) {
		ammo[i]->Update(50);
		
	}
	
	sphere.DrawDebug(position);
	
Move(input);
	
	
}


void Player3::PlayerInput(char* input){
	

	if(input[KEY_INPUT_A] == 1) {

	
	
		AttackTrigger();
		
	}
	
	
	
	

}

void Player3::Move(char* input)
{


	auto forward = camera.GetCameraForward(); // カメラの前方向ベクトル
	auto right = camera.GetCameraRight();     // カメラの右方向ベクトル

	// forwardとrightの初期化 (Y成分を0にして正規化)
	forward.y = 0;  // 地面に沿った移動を考慮してY軸を0に
	forward = VNorm(forward); // 正規化
	right.y = 0;
	right = VNorm(right);     // 正規化

	// 水平方向と垂直方向の移動をリセット
	VECTOR move = VGet(0.0f, 0.0f, 0.0f);
	int move_horizontal = 0;
	int move_vertical = 0;

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
	VECTOR moveH = VScale(right, move_horizontal * 5);  // 右方向に移動
	VECTOR moveV = VScale(forward, move_vertical * 5);  // 前方向に移動

	// 最終的な移動ベクトルを計算
	move = VAdd(moveH, moveV);

	// プレイヤーの位置を更新
	position = VAdd(position, move);
}


