#include "Camera.h"
#include "RootObject3D.h"

#include "Player3.h"



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
	
Move(input);
	
	
}


void Player3::PlayerInput(char* input){
	

	if(input[KEY_INPUT_A] == 1) {

	
	
		AttackTrigger();
		
	}
	
	
	
	

}

void Player3::Move(char* input)
{
	auto forward =camera.GetCameraForward();
	auto right = camera.GetCameraRight();

	//forwardÇ∆rightÇÃèâä˙âª(ê≥ãKâª)
	forward.y = 0;
	forward = VNorm(forward);
	right.y = 0;
	right = VNorm(right);

	//XZê¨ï™ÇÃà⁄ìÆë¨ìxÇàÍíUÉNÉäÉAÇ…Ç∑ÇÈ
	move.x = 0;
	move.z = 0;
	move.y = 0;
	move_horizontal = 0;
	move_vertical = 0;

	if (input[KEY_INPUT_LEFT] == 1) {

		move_horizontal = -1;

	}
	

	if (input[KEY_INPUT_RIGHT] == 1)
	{

		move_horizontal = 1;


	}


	if (input[KEY_INPUT_DOWN] == 1)
	{
		move_vertical = -1;
	}
	
	if (input[KEY_INPUT_UP] == 1)
	{
		move_vertical= 1;
	}
	
	
	auto moveH =VAdd(move, right);
	moveH = VScale(moveH, move_horizontal*5);
	
	auto moveV =VAdd(move,forward);
	moveV = VScale(moveV, move_vertical*5);

	move = VAdd(move, VAdd(moveH, moveV));
	
   position = VAdd(position, move);
}


