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
}

void Enemy::Move()
{
	position.x += 2;

	if (position.x > SCREEN_WIDTH_MAX)
	{
		position.x = 0;
		position.y += 50;
	}

	if (position.y > SCREEN_HEIGHT_MAX)
	{
		position.y = 0;
	}
	for (int i = 0; i < 10; i++)
	{

		ammo[i]->EnemyUpdate();

	}

}

void Enemy::Attack(const Player& player)
{
	
		if (ammo[ammoindex]->GetIsActive() == false) {
			ammo[ammoindex]->Shot(this->position.x, this->position.y);
			DrawFormatString(50, 70, GetColor(0, 255, 0), L"�e:%d", ammoindex);
			ammo[ammoindex]->isActive = true;
			ammoindex++;
			if (ammoindex == MAX_AMMO - 1) {
				for (int j = 0; j < MAX_AMMO; j++)
				{
					if (ammo[j]->isActive == true) {
						ammo[j]->isActive = false;
					}
					ammoindex = 0;
				}

				//���̑S�T���ł͌v�Z�ʂ��G���j�b�g�Ɣ��Ƃǂ��Ȃ�̂��E�E�E�E�ő��n^10?
				//���񎞍l���邪�A�O�̂��ߓ񕪒T����������悤���K���Ă����B
			}
		}
	
	
}

