
#include "Player2.h"
#include "Enemy2.h"

#include "ObjectAdmin2D.h"
#include <iostream>


void ObjectAdmin2D::Init2D()
{

	object[0] = std::make_shared<Player2>(VGet(320,240,0));


	object[0]->Init2D(L"C:\\Users\\hatte\\source\\repos\\ShootingGame2024\\ShootingGame3D\\モデル\\無題.mv1");
	object[0]->isEnemy = false;
	
	for (int enemyindex = 1; enemyindex < 10; enemyindex++) {
		auto x = 0;
		object[enemyindex] = std::make_shared<Enemy2>((VGet(100,200,0)));


	}
object[1]->Init2D(L"C:\\Users\\hatte\\source\\repos\\ShootingGame2024\\ShootingGame3D\\モデル\\Enemy.mv1");

	//x += 100;
	//object[1]->isEnemy = true;
}

void ObjectAdmin2D::Update2D(char* input)
{
	for (int i = 0; i < MAX_AMMO; i++)
	{
		object[0]->ammo[i]->Update(10, object[0]->position, object[0]->lockontheta);
		object[1]->ammo[i]->Update(-10, object[1]->position, object[1]->lockontheta);
	}
	object[0]->Update(input);
	object[0]->Update();
	object[0]->UpdateCore2D();
	for (int enemyindex = 1; enemyindex < 10; enemyindex++) {
		auto x = 0;
		//object[enemyindex]->Update(VGet(200, 200, 500));

	}
	object[1]->Update();
	object[1]->UpdateCore2D();
	Check_ObjectIsActive();


}

void ObjectAdmin2D::Draw2D()
{
}

void ObjectAdmin2D::judge()
{
	Check_ObjectIsActive();
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

	//Trigger_Intersect3D()の、objectindexとtargetindexを引き継ぐ。
	//つまりobjectindex側のオブジェクトが弾を撃った側のオブジェクトで、
	//targetindexは弾が当たった側のオブジェクトになる
	//Sphere::Intersectで衝突判定を行う。
	//弾を撃つ側の弾と、撃たれる側の球体の衝突判定をおこなう
	//真ならHITをコンソールに出力する。
	for (int ammoindex = 0; ammoindex < 10; ammoindex++) {
		if (Circle::Intersect(object[objectindex]->ammo[ammoindex]->circle, object[targetindex]->circle))
		{

			DrawFormatString(600, 200, GetColor(255, 100, 0), L"HIT");
		}
	}


	
}