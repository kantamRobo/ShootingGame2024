#include "Player3.h"
#include "ObjectAdmin3D.h"
#include "Enemy3D.h"


void ObjectAdmin3D::Init3D()
{
	object[0] = std::make_shared<Player3>();
	object[1] = std::make_shared<Enemy3D>();
    object[0]->Init3D(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\���f��\\����.mv1");
	object[1]->Init3D(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\���f��\\Enemy.mv1");

}

void ObjectAdmin3D::Update3D(char* input)
{
	object[0]->Update(VGet(100, 200, 500));
	object[1]->Update(VGet(200, 200, 500));
}

void ObjectAdmin3D::Draw3D()
{
}

void ObjectAdmin3D::judge3D()
{
}
