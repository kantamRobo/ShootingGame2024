
#include "ObjectAdmin.h"
#include "Ammo.h"
#include <DxLib.h>



void ObjectAdmin::Init()
{

	object[0] = std::make_shared<Player>();
	object[0]->Create(320, 240);
	//�����̂������������B
		object[1] = std::make_shared<Enemy>();
	
	object[1]->Create(100, 100);
}

void ObjectAdmin::Update(char* input)
{
	object[0]->Update(input);
	object[1]->Update();
}

void ObjectAdmin::Draw()
{
	object[0]->Draw();
	object[1]->Draw();
}

void ObjectAdmin::judge()
{
	for (int i = 0; i < 2; i++) {
		for (int t = 0; t < 10; t++) {
			int bullet_x = object[i]->ammo[t]->position.x;

			int bullet_y = object[i]->ammo[t]->position.y;

			double bullet_area = object[i]->ammo[t]->radius;


			int target_x = object[i]->position.x;

			int target_y = object[i]->position.y;

			double target_area = object[i]->radius;
			//�e�Ɣ�e����Unit�Ƃ̋�����肱���̔��a�̍��v���傫���A�^�C�v����s�^�C�v�Ȃ��e���Ă��鎖�ɂȂ�




			if((bullet_x - target_x)*(bullet_x - ((target_x)+(bullet_y - target_y)
						*
						(bullet_y - target_y)
						< (bullet_area + target_area)*(bullet_area + target_area))))
			{
				//TODO:�^�O��t����
				//Object[t]->Hit(Object[i]->GetAmmo(b));
				DrawFormatString(100, 100, GetColor(0, 255, 255), L"HIT");
				//Object[i]->GetAmmo(b)->DestroyAmmo();
				//score += 20;
				//NumofRepeledEnemy += 20;
			}else
			{
				return;
			}

		}
	}

}