#include "RootObject3D.h"
#include "Player3.h"

#include "DEFINE3D.h"


void Player3::Draw()
{
}

void Player3::Update()
{
	
}

void Player3::Update(char* input)
{
	Draw3D(position);
	for (int i = 0; i < MAX_AMMO; i++) {
		ammo[i]->Update(50);
		
	}
	
	sphere.DrawDebug(position);
	
	PlayerInput(input);
	
	
}


void Player3::PlayerInput(char* input){
	if (input[KEY_INPUT_LEFT] == 1) {

		position.x -= 5;

	}

	if (input[KEY_INPUT_RIGHT] == 1)
	{

		position.x += 5;


	}

	if (input[KEY_INPUT_UP] == 1)
	{
		position.z += 5;
	}

	if (input[KEY_INPUT_DOWN] == 1)
	{
		position.z -= 5;
	}

	if(input[KEY_INPUT_A] == 1) {

	
	
		AttackTrigger();
		
	}
	
	
	
	

}


