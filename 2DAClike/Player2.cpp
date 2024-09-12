#include "Player2.h"

void Player2::Update(char* input)
{
	DrawFormatString(320, 200, GetColor(0, 255, 0), L"Šp“x %f ", lockontheta);
	DrawFormatString(320, 180, GetColor(0, 255, 0), L"ƒfƒ‹ƒ^ƒ^ƒCƒ€: %f ", deltaTime);
	

	LockOnMove2D(VGet(100, 200, 0), lockontheta);
	
	if (input[KEY_INPUT_Z] == 1)
	{
		currentTime = GetNowCount();
		deltaTime = (currentTime - previousTime) / 1000.0f; // ƒ~ƒŠ•b‚©‚ç•b‚É•ÏŠ·

		quick_boostguage += 1;
		quick_boostguage %= 100;
		previousTime = GetNowCount();
		if (quick_boostguage % 100 > 0 && quick_boostguage % 100 < 10) {
			
			QuickBoost2DRight(VGet(100, 200, 0), lockontheta);


			

		}
		currentTime = 0;
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
//‚ 