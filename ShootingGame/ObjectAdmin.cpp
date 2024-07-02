
#include "ObjectAdmin.h"
#include "Ammo.h"
#include <DxLib.h>



void ObjectAdmin::Init()
{
	TITLE = LoadGraph(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame\\ShootingGame\\TITLE.png");
	GAMEOVER = LoadGraph(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame\\ShootingGame\\GAMEOVER.png");
	CLEAR = LoadGraph(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame\\ShootingGame\\CLEAR.png");
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

	switch (status)
	{

	case STATUS::TITLE:
		DrawGraph(0, 0, TITLE, 0);
		if (input[KEY_INPUT_SPACE])
		{
			status = STATUS::GAME;
		}
		break;
	case STATUS::GAME:
		object[0]->Update(input);
		Draw();
		DrawFormatString(500, 200, GetColor(255, 100, 0), L"HP%d", object[0]->health);
		for (int i = 1; i < 10; i++) {
			object[i]->Update();
			object[i]->EnemyMove();
			object[i]->Attack();
			if (object[0]->health < 0)
			{
				status = STATUS::RESULT;
			}
			if(object[i]->health <0)
			{
				status = STATUS::CLEAR;
			}
		}
		break;

	case STATUS::RESULT:
		DrawGraph(0, 0, GAMEOVER, 0);

		break;

	case STATUS::CLEAR:
		DrawGraph(0, 0, CLEAR, 0);
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
			for (int bullet = 0; bullet < 10; bullet++) {
				

					for (int target = 0; target < 10; target++) {
						if (object[target]->isActive) {

							if (object[i]->isEnemy != object[target]->isEnemy) {

								int bullet_x = object[i]->ammo[bullet]->position.x;
								int bullet_y = object[i]->ammo[bullet]->position.y;
								double bullet_area = object[i]->ammo[bullet]->radius;

								int target_x = object[target]->position.x;
								int target_y = object[target]->position.y;
								double target_area = object[target]->radius;

								

								double a = bullet_x - target_x;
								double b = bullet_y - target_y;
								double r1r2 = bullet_area + target_area;
							
								//敵とプレイヤーが接しているときに弾を撃つと衝突判定が起きる
								//弾と被弾するUnitとの距離よりこれらの半径の合計が大きく
								if ((a * a) + (b * b)
									< (r1r2) * (r1r2))
								{
									DrawFormatString(600, 200, GetColor(255, 100, 0), L"HIT");
									object[t]->health -= 1;
								}

								


							}

						}
					}

				
			}
		}
	}





}