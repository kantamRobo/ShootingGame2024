#pragma once


class Sphere;
#include "Ammo.h"
class Ammo3D:public Ammo
{
public:
	Ammo3D();
	Sphere sphere;
	void Shot3D(int m_x, int m_y,int m_z);
	void Update3D();
};

