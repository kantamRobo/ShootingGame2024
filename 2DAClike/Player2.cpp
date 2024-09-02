#include "Player2.h"

void Player2::Update(char* input)
{

	auto radius = 1.0f;


	

	if (input[KEY_INPUT_LEFT] == 1) {
		

			lockontheta -= 0.1f;
		
	}

	if (input[KEY_INPUT_RIGHT] == 1)
	{
		
			lockontheta += 0.1f;

		
	}

	

	LockOnMove2D(VGet(100,200,0), lockontheta,distance);
}



void Player2::Update()
{
	
	Draw2D(this->position);
}
//‚ 