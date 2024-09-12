#include "Player2.h"

void Player2::Update(char* input)
{
	DrawFormatString(320, 200, GetColor(0, 255, 0), L"角度 %f ", lockontheta);
	DrawFormatString(320, 180, GetColor(0, 255, 0), L"デルタタイム: %f ", deltaTime);
	DrawFormatString(320, 120, GetColor(0, 255, 0), L"ブーストリミット: % f ", boostlimit);




	LockOnMove2D(VGet(100, 200, 0), lockontheta);

	if (input[KEY_INPUT_Z] == 1 && isButtonReleased == true)
	{
		isButtonPressed = true;
		isButtonReleased = false;
		//Zを一瞬だけ押すと、テレポートする。
		currentTime = static_cast<float>(GetNowCount());
		deltaTime = static_cast<float>(currentTime - previousTime) / 4000; // ミリ秒から秒に変換



		previousTime = static_cast<float>(GetNowCount());

		if (boostlimit < 0.1) {
			QuickBoost2DRight(VGet(100, 200, 0), lockontheta);
			boostlimit = EditableBoostLimitParam;
		}



		currentTime = 0;
		deltaTime = 0;
		quick_boostguage = 0;
	}else if (input[KEY_INPUT_Z] ==0)
	{
		isButtonReleased = true;
		isButtonPressed = false;
		

		boostlimit -= static_cast<float>(0.1);

			

		
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