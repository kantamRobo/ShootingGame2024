#pragma once


class Sphere;
#include "IAmmo.h"
class Ammo3D:public IAmmo
{
public:
	Ammo3D() {};
	Sphere sphere;
	
	void Shot3D(float m_x, float m_y, float m_z);
	
	Ammo3D(const VECTOR& pos);

	void Draw();
	void Update(const float AMMOVELOCITY);
	void Move3D(const float AMMOVELOCITY);
	void Attack3D(const VECTOR& shotpos);

	void Trigger(const VECTOR& shotpos);

	
	
	int ammomodel;
	
	//ダーティフラグ
};

