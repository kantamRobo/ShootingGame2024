
#include "RootObject3D.h"
#include "Camera.h"
#include "Player3.h"



void Player3::Draw()
{
}


void Player3::Update(const MATRIX& transform, Camera* camera, char* input)
{
	Draw3D(position);
	for (int i = 0; i < MAX_AMMO; i++) {
		ammo[i]->Update(50);
		
	}
	
	sphere.DrawDebug(position);
	
Move(transform,camera,input);
	
	
}


void Player3::PlayerInput(char* input){
	

	if(input[KEY_INPUT_A] == 1) {

	
	
		AttackTrigger();
		
	}
	
	
	
	

}


void Player3::Move(const MATRIX& transform, Camera* camera, char* input)
{
	// カメラの前方向と右方向を表示 (デバッグ)
	DrawFormatString(320, 180, GetColor(0, 255, 0), L"前方ベクトルz %f ", camera->GetCameraForward().z);
	DrawFormatString(320, 160, GetColor(0, 255, 0), L"前方ベクトルx %f ", camera->GetCameraForward().x);
	DrawFormatString(320, 200, GetColor(0, 255, 0), L"右ベクトルx %f ", camera->GetCameraRight().x);
	DrawFormatString(320, 220, GetColor(0, 255, 0), L"右ベクトルz %f ", camera->GetCameraRight().z);
	DrawFormatString(320, 280, GetColor(0, 255, 0), L"movetempx_admin %f ", camera->movetempx);
	DrawFormatString(320, 300, GetColor(0, 255, 0), L"movetempy_admin %f ", camera->movetempy);

	// カメラの前方向と右方向ベクトルを取得
	VECTOR forward = VGet(camera->GetCameraForward().x, 0.0f, camera->GetCameraForward().z);  // Y成分を0にして、地面に沿った動きにする
	forward = VNorm(forward);  // 正規化

	VECTOR right = VGet(camera->GetCameraRight().x, 0.0f, camera->GetCameraRight().z);  // 同様に右方向ベクトルもY成分を0に
	right = VNorm(right);  // 正規化

	// 水平方向と垂直方向の移動量をリセット
	VECTOR move = VGet(0.0f, 0.0f, 0.0f);
	int move_horizontal = 0;
	int move_vertical = 0;

	// 入力に応じて移動量を設定 (上下左右キーによる操作)
	if (input[KEY_INPUT_UP] == 1) {
		move_vertical = -1;  // 前進
	}
	if (input[KEY_INPUT_DOWN] == 1) {
		move_vertical = 1;  // 後退
	}
	if (input[KEY_INPUT_LEFT] == 1) {
		move_horizontal = 1;  // 左移動
	}
	if (input[KEY_INPUT_RIGHT] == 1) {
		move_horizontal = -1;  // 右移動
	}

	// カメラ基準での移動ベクトルを計算
	VECTOR moveH = VScale(camera->GetCameraRight(), move_horizontal * 5.0f);  // 右方向に移動
	VECTOR moveV = VScale(camera->GetCameraForward(), move_vertical * 5.0f);  // 前方向に移動

	// 最終的な移動ベクトルを計算
	move = VAdd(moveH, moveV);  // 水平方向と垂直方向の移動ベクトルを合成
	move.y = 0;  // 地面に沿った移動とするためY成分は0
	　
	// プレイヤーの位置を更新
	position = VAdd(position, move);

	// 移動方向を図示
	VECTOR endPos = VAdd(position, VScale(move, 1000.0f));  // 移動方向を視覚化する線の終点
	DrawLine3D(position, VAdd(position, VScale(forward, 1000)), GetColor(0, 255, 0));  // 緑色で前方向を描画
	DrawLine3D(position, VAdd(position, VScale(right, 1000)), GetColor(255, 255, 255));  // 白色で右方向を描画
	DrawLine3D(position, endPos, GetColor(255, 0, 0));  // 赤色で移動方向を描画
}
/*
void Player3::Move(const MATRIX& transform, Camera* camera,char* input)
{

	
	
	DrawFormatString(320, 180, GetColor(0, 255, 0), L"前方ベクトルz %f ", camera->GetCameraForward().z);
	DrawFormatString(320, 160, GetColor(0, 255, 0), L"前方ベクトルx %f ", camera->GetCameraForward().x);
	DrawFormatString(320, 200, GetColor(0, 255, 0), L"右ベクトルx %f ", camera->GetCameraRight().x);
	DrawFormatString(320, 220, GetColor(0, 255, 0), L"右ベクトルz %f ", camera->GetCameraRight().z);
	DrawFormatString(320, 280, GetColor(0, 255, 0), L"movetempx_admin %f ", camera->movetempx);
	DrawFormatString(320, 300, GetColor(0, 255, 0), L"movetempy_admin %f ", camera->movetempy);

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
	

	//MV1SetRotationXYZ(handle, VGet(0, MGetRotY(playerRotationY), 0));
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
	move.y = 0;

	// プレイヤーの位置を更新
	position = VAdd(position, move);
	//プレイヤーの移動方向を図示
	   // 移動方向を図示
	VECTOR endPos = VAdd(position, VScale(VScale(move,100), 5.0f));  // 移動方向を視覚化する線の終点
    
	DrawLine3D(position, VAdd(position,VScale(camera->GetCameraForward(), 1000)), GetColor(0, 255, 0));  // 緑色で線を描画
	DrawLine3D(position, VAdd(position,VScale(camera->GetCameraRight(), 1000)), GetColor(255, 255, 255));//白で線を描画 
	DrawLine3D(position, endPos, GetColor(255, 0, 0));  // 赤色で線を描画
	
}
*/

//ミスコード
/*


カメラの前方向ベクトルと右方向ベクトルの計算が正常に動作しない
void ObjectAdmin3D::Update3D(char* input)
{
	camera.Update(input,object[0]->position);
	camera.UpdateDirection(camera.moveX, camera.moveY);
...
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




	// カメラの設定に反映する
	SetCameraPositionAndTarget_UpVecY(position, CameraLookAtPosition);






}


void Camera::UpdateDirection(float in_x,float in_y)
{
	DrawFormatString(320, 250, GetColor(0, 255, 0), L"movetempy_cam %f ", in_x);
	DrawFormatString(320, 270, GetColor(0, 255, 0), L"movetempx_cam %f ", in_y);
	forward = VNorm(VGet(
		cos(in_x) * sin(in_y),
		sin(in_y),
		cos(in_y) * cos(in_x)
	));

	right = VNorm(VGet(
		cos(in_x),
		0.0f,
		-sin(in_y)
	));


		//Camera_FORWARD = VGet(View.m[2][0], View.m[2][1], View.m[2][2]);
		//Camera_Right = VGet(View.m[0][0], View.m[0][1], View.m[0][2]);

}
*/