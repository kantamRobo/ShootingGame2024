
#include "Player3.h"


Player3::Player3()
{
	sphere.position = position;
	sphere.radius = 10;
}
void Player3::Draw()
{
}

void Player3::Update()
{
	
}

void Player3::Update(char* input)
{
	if (input[KEY_INPUT_Z])
	{

		Attack3D();


	}
	
}
