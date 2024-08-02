#include "SphereCollision.h"
#include "Ammo3D.h"

Ammo3D::Ammo3D()
{
	sphere.position = position;

	sphere.radius = 40;
}

void Ammo3D::Shot3D(int m_x, int m_y, int m_z)
{
	position.x = m_x;
	position.y = m_y;
	position.z = m_z;
	isActive = true;
}


void Ammo3D::Update3D()
{
	sphere.DrawDebug(position);

	position.z -= AMMOVELOCITY;
}