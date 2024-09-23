#include "Player2.h"

void Player2::Update(char* input)
{
	DrawFormatString(320, 200, GetColor(0, 255, 0), L"角度 %f ", lockontheta);
	DrawFormatString(320, 180, GetColor(0, 255, 0), L"デルタタイム: %f ", deltaTime);
	DrawFormatString(320, 120, GetColor(0, 255, 0), L"ブーストリミット: % f ", boostlimit);
	DrawFormatString(320, 220, GetColor(0, 255, 0), L"クーリングゲージ: % f ", coolingtime);
	coolingtime /= 10000;
	//Zを一瞬だけ押すと、テレポートする。
	currentTime = static_cast<float>(GetNowCount());
	deltaTime = (currentTime - moveStartTime) / 1000.0f;



	LockOnMove2D(VGet(100, 200, 0), lockontheta);

	// Zキーを押したときに0.2秒間移動
	if (input[KEY_INPUT_Z] == 1 && !isMoving)
	{
		isMoving = true;
		moveStartTime = GetNowCount(); // 移動を開始した時間を記録
	}

	// 移動が有効な場合
	if (isMoving)
	{
		// 現在の時間と移動開始時間を比較して、移動時間が0.2秒未満なら移動
		float currentTime = GetNowCount();
		if (deltaTime< moveDuration)
		{
			// ここで移動処理を実行します
			lockontheta += 0.2f*deltaTime;  // 例: 5ピクセル右に移動
		}
		else
		{
			// 移動時間が過ぎたら停止
			isMoving = false;
		}
	}
	if (input[KEY_INPUT_UP] == 1)
	{
		distance += 0.5;
		DrawFormatString(320, 240, GetColor(0, 255, 0), L" %f ", distance);
	}

	if (input[KEY_INPUT_DOWN] == 1)
	{
		distance -= 0.5;
		DrawFormatString(320, 240, GetColor(0, 255, 0), L" %f ", distance);
	}

	if (input[KEY_INPUT_LEFT] == 1) {


		lockontheta -= 0.1f;

	}

	if (input[KEY_INPUT_RIGHT] == 1)
	{

		lockontheta += 0.1f;


	}
	if (input[KEY_INPUT_A] == 1)
	{

		AttackTrigger();
	}




}


void Player2::Update()
{
	
	Draw2D(this->position);
}
//あ