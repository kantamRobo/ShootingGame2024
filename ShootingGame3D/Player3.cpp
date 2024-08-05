
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
	if (input[KEY_INPUT_Z])
	{

		Attack3D();


	}
	
}

void Player3::Update(char* input)
{
}
