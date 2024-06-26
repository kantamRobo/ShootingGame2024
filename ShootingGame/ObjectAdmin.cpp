
#include "ObjectAdmin.h"
#include "Ammo.h"
#include <DxLib.h>



void ObjectAdmin::Init()
{
	auto x = 0;
	object[0] = std::make_shared<Player>();
	object[0]->Create(320, 240);
	object[0]->isEnemy = false;
	//�����̂������������B
	for (int i = 1; i < 10; i++) {
		object[i] = std::make_shared<Enemy>();
		
		
		object[i]->Create(0+x, 100);
		
		object[i]->isEnemy = true;

		x += 20;
	}


}

void ObjectAdmin::Update(char* input)
{
	object[0]->Update(input);
	
	for (int i = 1; i < 10; i++) {
		object[i]->Update();
		object[i]->EnemyMove();
		object[i]->Attack();
		
	}
	
}

void ObjectAdmin::Draw()
{
	object[0]->Draw();
	for (int i = 1; i < 10; i++) {
		object[i]->Draw();
	}
}

void ObjectAdmin::judge()
{

	for (int i = 0; i < 10; i++) {
		if (object[i]->isActive) {
			for (int b = 0; b < 10; b++) {
				

					for (int t = 0; t < 10; t++) {
						if (object[t]->isActive) {

							if (object[i]->isEnemy != object[t]->isEnemy) {

								int bullet_x = object[i]->ammo[b]->position.x;
								int bullet_y = object[i]->ammo[b]->position.y;
								double bullet_area = object[i]->ammo[b]->radius;

								int target_x = object[t]->position.x;
								int target_y = object[t]->position.y;
								double target_area = object[t]->radius;

								//int barrier_x = barrier->GetPosX();
								//int barrier_y = barrier->GetPosY();
								//double barrier_area = barrier->GetHitZone();

								double a = bullet_x - target_x;
								double b = bullet_y - target_y;
								double r1r2 = bullet_area + target_area;
							
								//�G�ƃv���C���[���ڂ��Ă���Ƃ��ɒe�����ƏՓ˔��肪�N����
								//�e�Ɣ�e����Unit�Ƃ̋�����肱���̔��a�̍��v���傫��
								if ((a * a) + (b * b)
									< (r1r2) * (r1r2))
								{
									DrawFormatString(600, 200, GetColor(255, 100, 0), L"HIT");
									/*
									Object[t]->Hit(Object[i]->GetAmmo(b));
									Object[i]->GetAmmo(b)->DestroyAmmo();
									score += 20;
									NumofRepeledEnemy += 20;
									*/
								}

								/*
								if (barrier->GetisActive())
								{
									if ((bullet_x - barrier_x)*(bullet_x - barrier_x) + (bullet_y - barrier_y)*(bullet_y - barrier_y)
										<
										(bullet_area + barrier_area)*(bullet_area + barrier_area))
									{
										Object[i]->GetAmmo(b)->DestroyAmmo();
									}
								}*/


							}

						}
					}

				
			}
		}
	}





}