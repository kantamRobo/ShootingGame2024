#include "Player2.h"

void Player2::Update(char* input)
{
	DrawFormatString(320, 200, GetColor(0, 255, 0), L"角度 %f ", lockontheta);
	DrawFormatString(320, 180, GetColor(0, 255, 0), L"デルタタイム: %f ", deltaTime);
	DrawFormatString(320, 120, GetColor(0, 255, 0), L"クイックブースト: % f ", quick_boostguage);




	LockOnMove2D(VGet(100, 200, 0), lockontheta);
	
	if (input[KEY_INPUT_Z] == 1&&isButtonPressed ==false) 
	{
		

		//Zを一瞬だけ押すと、テレポートする。
		currentTime = static_cast<float>(GetNowCount());
		deltaTime = static_cast<float>(currentTime - previousTime)/4000; // ミリ秒から秒に変換

		quick_boostguage += 5;
		
		previousTime = GetNowCount();

	if (quick_boostguage > 10) {
			QuickBoost2DRight(VGet(100, 200, 0), lockontheta);
			isButtonPressed = true;
			isButtonReleased = false;
			quick_boostguage = 0;
		}

			
        //if (quick_boostguage % 100 > 1 && quick_boostguage % 100 < 15) {
		//}
		currentTime = 0;
		
	}
	else
	{
		isButtonReleased = true;
		isButtonPressed = false;
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