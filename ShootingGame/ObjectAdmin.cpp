#include "ObjectAdmin.h"
#include "Ammo.h"
void ObjectAdmin::judge()
{
	int bullet_x = Object[i]->GetAmmo(b)->GetPosX();

	int bullet_y = Object[i]->GetAmmo(b)->GetPosY();

	double bullet_area = Object[i]->GetAmmo(b)->GetHitZone();


	int target_x = Object[t]->GetPosX();

	int target_y = Object[t]->GetPosY();

	double target_area = Object[t]->GetHitZone();
	//�e�Ɣ�e����Unit�Ƃ̋�����肱���̔��a�̍��v���傫���A�^�C�v����s�^�C�v�Ȃ��e���Ă��鎖�ɂȂ�

	//�e��x���W���v�Z����
	float bullet_x = ammo[i].position.x;
	//�e��y���W���v�Z����
	float bullet_y = ammo[i].position.y;
	//�e�̔��a���v�Z����
	float radius = ammo[i].radius;
	if
		((bullet_x - target_x)
			*
			(bullet_x - ((target_x)+
				(bullet_y - target_y)
				*
				(bullet_y - target_y)
				< (bullet_area + target_area)
				*
				(bullet_area + target_area))
	{

		Object[t]->Hit(Object[i]->GetAmmo(b));
		Object[i]->GetAmmo(b)->DestroyAmmo();
		score += 20;
		NumofRepeledEnemy += 20;
	}

}
