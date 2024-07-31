#pragma once
class Ammo;
#include "Ammo.h"
class Ammo3D:public Ammo
{
public:
	Ammo3D();
	void Shot3D(int m_x, int m_y,int m_z);
};

