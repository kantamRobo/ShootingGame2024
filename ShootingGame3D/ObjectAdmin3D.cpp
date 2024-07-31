#include "SphereCollision.h"
#include "Player3.h"
#include "Enemy3D.h"
#include "Ammo.h"
#include "Ammo3D.h"
#include "ObjectAdmin3D.h"


void ObjectAdmin3D::Init3D()
{
	
	object[0] = std::make_shared<Player3>();
	
	ammo3d[0] = std::make_shared<Ammo3D>();
    object[0]->Init3D(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\ƒ‚ƒfƒ‹\\–³‘è.mv1", VGet(100, 200, 500));
	for (int enemyindex = 1; enemyindex < 10; enemyindex++) {
		auto x = 0;
		object[enemyindex] = std::make_shared<Enemy3D>();
	
	object[enemyindex]->Init3D(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\ƒ‚ƒfƒ‹\\Enemy.mv1",(VGet(200+x, 500, 500)));
	x += 100;
	}
	object[2]->Init3D(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\ƒ‚ƒfƒ‹\\’e.mv1", (VGet(300, 200, 500)));

	camera.Init(object[0]->position, object[1]->position);
}

void ObjectAdmin3D::Update3D(char* input)
{
	camera.Update(input);
	object[0]->Update(VGet(100, 200, 500));
	
	
	for (int enemyindex = 1; enemyindex < 10; enemyindex++) {
		auto x = 0;
		object[enemyindex]->Update(VGet(200, 200, 500));
		if (input[KEY_INPUT_D] == 1) {

			object[enemyindex]->position.x += 10;
		}

		if (input[KEY_INPUT_A] == 1) {

			object[enemyindex]->position.x -= 10;
		}

		if (input[KEY_INPUT_W] == 1) {

			object[enemyindex]->position.y += 10;
		}

		if (input[KEY_INPUT_S] == 1) {

			object[enemyindex]->position.y -= 10;
		}

		if (input[KEY_INPUT_Q] == 1)
		{
			object[enemyindex]->position.z += 10;
		}

		if (input[KEY_INPUT_Z] == 1)
		{
			object[enemyindex]->position.z -= 10;
		}

	}
	//object[2]->Update(VGet(300, 200, 500));
	

	
}

void ObjectAdmin3D::Draw3D()
{
}

void ObjectAdmin3D::judge3D()
{
}
