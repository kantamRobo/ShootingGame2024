#include "Player3.h"
#include "ObjectAdmin3D.h"



void ObjectAdmin3D::Init3D()
{
	object[0] = std::make_shared<Player3>();

    object[0]->Init3D(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\ƒ‚ƒfƒ‹\\–³‘è.mv1");


}

void ObjectAdmin3D::Update3D(char* input)
{
	object[0]->Update(VGet(100, 200, 500));

}

void ObjectAdmin3D::Draw3D()
{
}

void ObjectAdmin3D::judge3D()
{
}
