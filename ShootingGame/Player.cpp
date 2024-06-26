#include "DEFINE.h"
#include "Player.h"
#include "Ammo.h"
void Player::Update()
{
}
void Player::Draw()
{
	DrawCircle(position.x, position.y, radius, Color, TRUE);
}


void Player::Create(double xpos, double ypos)
{
	position.x = xpos;
	position.y = ypos;
	for (int i = 0; i < 10; i++)
	{
		ammo[i] = std::make_shared<Ammo>();
	}
	//�v���C���[�L�����N�^�[�̏ꏊ�����߂�B
 //xpos,ypos�Ƃ����̂́A�u�֐�(���񂷂�)�̈���(�Ђ�����)�v�ƌ�������̂ŁA
//���̊֐����Ăяo���Ƃ��ɁA�Q�[�����n�܂����Ƃ��ɁA�v���C���[���o�Ă���ꏊ
//�͂ǂ��ɂ��邩�H�Ƃ����̂����߂�̂Ɏg���B
	isEnemy = false;
	radius = 10;
}


void  Player::Update(char* input)
{

	for (int i = 0; i < MAX_AMMO; i++)
	{

		ammo[i]->Update();


	}


	if (input[KEY_INPUT_UP] == 1)
	{
		if (position.y > 0)
		{
			position.y -= 5;
			//posY -= 5;
		}
	}

	if (input[KEY_INPUT_DOWN] == 1)
	{
		if (position.y < SCREEN_WIDTH_MAX)
		{
			position.y += 5;
			//posY += 5;
		}
	}

	if (input[KEY_INPUT_LEFT] == 1) {
		if (position.x > 0) {

			position.x -= 5;
		}
	}

	if (input[KEY_INPUT_RIGHT] == 1)
	{
		if (position.x < SCREEN_WIDTH_MAX)
		{
			position.x += 5;

		}
	}

	if (input[KEY_INPUT_Z])
	{

		Attack();


	}


}
	
