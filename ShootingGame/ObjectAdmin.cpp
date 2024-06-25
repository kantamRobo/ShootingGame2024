
#include "ObjectAdmin.h"
#include "Ammo.h"
#include <DxLib.h>



void ObjectAdmin::Init()
{

	object[0] = std::make_shared<Player>();
	object[0]->Create(320, 240);
	//ここのやり方を説明する。
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
			//弾と被弾するUnitとの距離よりこれらの半径の合計が大きく、タイプが飛行タイプなら被弾している事になる




			if((bullet_x - target_x)*(bullet_x - ((target_x)+(bullet_y - target_y)
						*
						(bullet_y - target_y)
						< (bullet_area + target_area)*(bullet_area + target_area))))
			{
				//TODO:タグを付ける
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