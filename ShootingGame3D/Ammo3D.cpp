#include "SphereCollision.h"
#include "Ammo3D.h"

Ammo3D::Ammo3D()
{
	sphere.position = position;

	sphere.radius = 40;
	ammomodel= MV1LoadModel(L"C:\\Users\\hiz108\\source\\repos\\ShootingGame2024\\ShootingGame3D\\ƒ‚ƒfƒ‹\\’e.mv1");
}

void Ammo3D::Shot3D(int m_x, int m_y, int m_z)
{
	position.x = m_x;
	position.y = m_y;
	position.z = m_z;
	isActive = true;
}

void Ammo3D::Draw()
{
	
	MV1DrawModel(ammomodel);

	
}
void Ammo3D::Update3D(const float AMMOVELOCITY)
{

	Draw();
	/*
		Move3D(AMMOVELOCITY);
	
	sphere.DrawDebug(position);
	*/
	MV1SetPosition(ammomodel, position);

	Move3D(AMMOVELOCITY);
	
}

void Ammo3D::Move3D(const float AMMOVELOCITY)
{
	position.z = AMMOVELOCITY;
}
