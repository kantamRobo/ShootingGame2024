
#include "ObjectAdmin.h"
#include "Ammo.h"
#include <DxLib.h>



void ObjectAdmin::Init()
{
	auto x = 0;
	object[0] = std::make_shared<Player>();
	object[0]->Create(320, 240);
	object[0]->isEnemy = false;
	//ここのやり方を説明する。
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
				if (object[i]->ammo[b]->isActive) {

					for (int t = 0; t < 10; t++) {
						if (object[t]->isActive) {

							if (object[i]->isEnemy != object[t]->isEnemy) {

								int bullet_x = object[i]->ammo[b]->position.x;
								int bullet_y = object[i]->ammo[b]->position.y;
								double bullet_area = object[i]->ammo[b]->radius;

								int target_x = object[t]->position.x;//初期化値にかかわらず、位置ベクトルがすべて0になっている。おそらくPlayerではなく
								int target_y = object[t]->position.y;
								double target_area = object[t]->radius;

								//int barrier_x = barrier->GetPosX();
								//int barrier_y = barrier->GetPosY();
								//double barrier_area = barrier->GetHitZone();

								//弾と被弾するUnitとの距離よりこれらの半径の合計が大きく
								if ((bullet_x - target_x) * (bullet_x - target_x) + (bullet_y - target_y) * (bullet_y - target_y)
									< (bullet_area + target_area) * (bullet_area + target_area)) {
									DrawFormatString(20, 50, GetColor(255, 100, 0), L"HIT");
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





}