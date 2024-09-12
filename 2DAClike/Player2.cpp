#include "Player2.h"

void Player2::Update(char* input)
{

	


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
	

	LockOnMove2D(VGet(100,200,0), lockontheta);
}



void Player2::Update()
{
	
	Draw2D(this->position);
}
//‚ 