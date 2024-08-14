
#include "Player3.h"
#include "Enemy3D.h"
#include "ObjectAdmin2D.h"
#include <iostream>


void ObjectAdmin2D::Init2D()
{

	object[0] = std::make_shared<Player2>(VGet(100, 580.000000, 500));


	//object[0]->Init3D(L"C:\\Users\\hatte\\source\\repos\\ShootingGame2024\\ShootingGame3D\\モデル\\無題.mv1");
	object[0]->isEnemy = false;
	for (int enemyindex = 1; enemyindex < 10; enemyindex++) {
		auto x = 0;
		object[enemyindex] = std::make_shared<Enemy2D>((VGet(150.000000, 580.000000, 2270)));


	}
//	object[1]->Init3D(L"C:\\Users\\hatte\\source\\repos\\ShootingGame2024\\ShootingGame3D\\モデル\\Enemy.mv1");
	//x += 100;
	//object[1]->isEnemy = true;
}

void ObjectAdmin2D::Update2D(char* input)
{
	
	object[0]->Update(input);


	for (int enemyindex = 1; enemyindex < 10; enemyindex++) {
		auto x = 0;
		//object[enemyindex]->Update(VGet(200, 200, 500));

	}
	object[1]->Update();

	Check_ObjectIsActive();


}

void ObjectAdmin2D::Draw2D()
{
}


void ObjectAdmin2D::Check_ObjectIsActive()
{
	for (int i = 0; i < 2; i++) {
		if (object[i]->isActive) {

			Trigger_Intersect2D();
		}
	}
}
void ObjectAdmin2D::Trigger_Intersect2D()
{
	//objectindexとtargetindexが
	for (int objectindex = 0; objectindex < 2; objectindex++)
	{
		for (int targetindex = 0; targetindex < 2; targetindex++) {
			if (object[objectindex]->isEnemy != object[targetindex]->isEnemy) {
				Test_Intersect2D(objectindex, targetindex);
			}
		}

	}
}



//Circleの当たり判定に使う
void ObjectAdmin2D::Test_Intersect2D(int objectindex,int targetindex)
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
								object[target]->health -= 1;
							}




						}

					}
				}


			}
		}
	}





}