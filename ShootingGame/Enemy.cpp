#include "Ammo.h"
#include "Player.h"
#include "Enemy.h"
#include "DEFINE.h"

void Enemy::Draw()
{
	DrawCircle(position.x, position.y, radius, Color, TRUE);
}


void Enemy::Create(double xpos, double ypos)
{
	position.x = xpos;
	position.y = ypos;
	//�v���C���[�L�����N�^�[�̏ꏊ�����߂�B
 //xpos,ypos�Ƃ����̂́A�u�֐�(���񂷂�)�̈���(�Ђ�����)�v�ƌ�������̂ŁA
//���̊֐����Ăяo���Ƃ��ɁA�Q�[�����n�܂����Ƃ��ɁA�v���C���[���o�Ă���ꏊ
//�͂ǂ��ɂ��邩�H�Ƃ����̂����߂�̂Ɏg���B
	for (int i = 0; i < 10; i++)
	{
		ammo[i] = std::make_shared<Ammo>();
	}
	isEnemy = true;
	radius = 20;
}


void Enemy::Update()
{
	
}


