
#include "Player3.h"
#include "Enemy3D.h"
#include "ObjectAdmin3D.h"
#include <iostream>


void ObjectAdmin3D::Init3D()
{
	
	object[0] = std::make_shared<Player3>(VGet(100, 580.000000, 500));
	
	
    object[0]->Init3D(L"C:\\Users\\hatte\\source\\repos\\ShootingGame2024\\ShootingGame3D\\ƒ‚ƒfƒ‹\\–³‘è.mv1");
	object[0]->isEnemy = false;
	for (int enemyindex = 1; enemyindex < 10; enemyindex++) {
		auto x = 0;
		object[enemyindex] = std::make_shared<Enemy3D>((VGet(150.000000, 580.000000, 2270)));
	
	
	}
	object[1]->Init3D(L"C:\\Users\\hatte\\source\\repos\\ShootingGame2024\\ShootingGame3D\\ƒ‚ƒfƒ‹\\Enemy.mv1");
	//x += 100;
	object[1]->isEnemy = true;
	camera.Init(object[0]->position, object[1]->position);
}

void ObjectAdmin3D::Update3D(char* input)
{
	camera.Update(input);
	object[0]->Update(input);
	
	
	for (int enemyindex = 1; enemyindex < 10; enemyindex++) {
		auto x = 0;
		//object[enemyindex]->Update(VGet(200, 200, 500));
	
	}
	object[1]->Update();

	Check_ObjectIsActive();

	
}

void ObjectAdmin3D::Draw3D()
{
}


void ObjectAdmin3D::Check_ObjectIsActive()
{
	for (int i = 0; i < 2; i++) {
		if (object[i]->isActive) {

			Trigger_Intersect3D();
		}
	}
}
void ObjectAdmin3D::Trigger_Intersect3D()
{
	//objectindex‚Ætargetindex‚ª
	for (int objectindex = 0; objectindex < 2; objectindex++)
	{
		for (int targetindex = 0; targetindex < 2; targetindex++) {
			if (object[objectindex]->isEnemy != object[targetindex]->isEnemy) {
				Test_Intersect3D(objectindex, targetindex);
			}
		}
		
	}
}

void ObjectAdmin3D::Test_Intersect3D(int objectindex,int targetindex) {
	for (int ammoindex = 0; ammoindex < 10; ammoindex++) {
		if (Sphere::Intersect(object[objectindex]->ammo[ammoindex]->sphere, object[targetindex]->sphere))
		{
			
			std::cout << "HIT" << std::endl;
			}
		}
	}
