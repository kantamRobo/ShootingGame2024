
#include "Ammo3D.h"

Ammo3D::Ammo3D()
{
}

void Ammo3D::Shot3D(int m_x, int m_y, int m_z)
{
	position.x = m_x;
	position.y = m_y;
	position.z = m_z;
	isActive = true;
}
