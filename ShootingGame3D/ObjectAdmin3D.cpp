
#include "Player3.h"
#include "Enemy3D.h"
#include "ObjectAdmin3D.h"
#include <iostream>


void ObjectAdmin3D::Init3D()
{
	
	object[0] = std::make_shared<Player3>();
	
	
    object[0]->Init3D(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\ƒ‚ƒfƒ‹\\–³‘è.mv1", VGet(100, 200, 500));
	for (int enemyindex = 1; enemyindex < 10; enemyindex++) {
		auto x = 0;
		object[enemyindex] = std::make_shared<Enemy3D>();
	
	object[enemyindex]->Init3D(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\ƒ‚ƒfƒ‹\\Enemy.mv1",(VGet(150.000000 +x, 580.000000, 2270)));
	x += 100;
	}
	object[2]->Init3D(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\ƒ‚ƒfƒ‹\\’e.mv1", (VGet(300, 200, 500)));
	
	camera.Init(object[0]->position, object[1]->position);
}

void ObjectAdmin3D::Update3D(char* input)
{
	camera.Update(input);
	object[0]->Update(input);
	
	
	for (int enemyindex = 1; enemyindex < 10; enemyindex++) {
		auto x = 0;
		//object[enemyindex]->Update(VGet(200, 200, 500));
		object[enemyindex]->Update();
	
	}
	//object[2]->Update(VGet(300, 200, 500));
	

	
}

void ObjectAdmin3D::Draw3D()
{
}

void ObjectAdmin3D::judge3D()
{
	for (int objectindex = 0; objectindex < ENEMY_MAX; objectindex++)
	{


		for (int ammoindex = 0; ammoindex < 10; ammoindex++) {
			if (Sphere::Intersect(object[objectindex]->ammo[ammoindex]->sphere, object[objectindex]->sphere))
			{
				std::cout << "HIT" << std::endl;
			}
		}
	}
}
