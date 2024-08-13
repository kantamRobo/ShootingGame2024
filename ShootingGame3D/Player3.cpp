
#include "Player3.h"
#include "DEFINE3D.h"

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
	for (int ammoindex = 0; ammoindex < MAX_AMMO; ammoindex++) {
		ammo[ammoindex]->Update(50);

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
	if (input[KEY_INPUT_A] == 1) {

		Attack3D();

	}





	

}
//一つのメソッドに3つ以上の分岐命令があるだけでも認知負荷に無理がある(疲れる)ので、関数にして分けてしまう
//PlayerのAttack3D()から、Ammo3DのAttack3D、そこから分岐命令を二つまでにして、それ以上になりそうなら関数を分ける。
void Player3::Attack3D()
{
	for (int ammoindex = 0; ammoindex < MAX_AMMO; ammoindex++)
	{
		ammo[ammoindex]->Attack3D(this->position);
	}
	
}