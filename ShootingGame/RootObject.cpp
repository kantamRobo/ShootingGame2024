#include "Ammo.h"
#include "RootObject.h"
#include "DEFINE.h"
void RootObject::Create(double in_x, double in_y)
{

	position.x = in_x;
	position.y = in_y;
	//�v���C���[�L�����N�^�[�̏ꏊ�����߂�B
 //xpos,ypos�Ƃ����̂́A�u�֐�(���񂷂�)�̈���(�Ђ�����)�v�ƌ�������̂ŁA
//���̊֐����Ăяo���Ƃ��ɁA�Q�[�����n�܂����Ƃ��ɁA�v���C���[���o�Ă���ꏊ
//�͂ǂ��ɂ��邩�H�Ƃ����̂����߂�̂Ɏg���B
	for (int i = 0; i < 10; i++)
	{
		ammo[i] = std::make_shared<Ammo>();
		ammo[i]->isActive = false;
	}
}

void RootObject::Attack()
{

	rapid++;

	rapid %= RAPID_RATE;

	if (rapid == 1) {

		if (ammo[ammoindex]->isActive == false) {
			ammo[ammoindex]->Shot(this->position.x, this->position.y - );
			ammo[ammoindex]->isActive = true;
			DrawFormatString(50, 70, GetColor(0, 255, 0), L"�e:%d", ammoindex);
			
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
}

void RootObject::EnemyMove()
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
