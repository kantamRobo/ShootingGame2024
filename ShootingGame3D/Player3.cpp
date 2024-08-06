
#include "Player3.h"


Player3::Player3()
{
	sphere.position = position;
	sphere.radius = 150;
}
void Player3::Draw()
{
}

void Player3::Update()
{
	
}

void Player3::Update(char* input)
{
	Draw3D(position);

	sphere.DrawDebug(position);
	     if (input[KEY_INPUT_UP] == 1)
		{

			position.y -= 5;


		}

		if (input[KEY_INPUT_DOWN] == 1)
		{

			position.y += 5;
			//posY += 5;

		}

		if (input[KEY_INPUT_LEFT] == 1) {

			position.x -= 5;

		}

		if (input[KEY_INPUT_RIGHT] == 1)
		{

			position.x += 5;


		}

		if (input[KEY_INPUT_Q] == 1)
		{
			position.z += 5;
		}

		if (input[KEY_INPUT_Z] == 1)
		{
			position.z -= 5;
		}
		if(input[KEY_INPUT_A] == 1)
		Attack3D();


	
	
}

