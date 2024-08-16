
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
	
	
	



	/*
	一つしか撃てなかったのではなく、
	ボタンを押すたびにfor文走って、そのイテレーターをそのままインデックスに使ってたから本来ならボタン押したらその分処理されるというのが一回の処理で
配列のインスタンス全部にアクセスしてしまってた。
	*/
	

}


