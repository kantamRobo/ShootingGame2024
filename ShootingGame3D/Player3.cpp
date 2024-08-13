
#include "Player3.h"
#include "DEFINE3D.h"

Player3::Player3()
{
	sphere.position = position;
	sphere.radius = 150;

	ammoindex = 0;
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

	
	
			bulletcounter++;
			bulletcounter %= 100;
			if (bulletcounter % 4 == 0) {
				ammoindex++;
				Attack3D(ammoindex);
			}
		
	}
	else if (ammoindex == MAX_AMMO)
	{
		ammoindex = 0;
	}
	
	




	

}
//��̃��\�b�h��3�ȏ�̕��򖽗߂����邾���ł��F�m���ׂɖ���������(����)�̂ŁA�֐��ɂ��ĕ����Ă��܂�
//Player��Attack3D()����AAmmo3D��Attack3D�A�������番�򖽗߂��܂łɂ��āA����ȏ�ɂȂ肻���Ȃ�֐��𕪂���B
void Player3::Attack3D(int index)
{
	
	
		
			ammo[index]->Attack3D(this->position);

		
	
		
	
		
}
