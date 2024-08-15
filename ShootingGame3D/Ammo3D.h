#pragma once


class Sphere;
#include "IAmmo.h"
class Ammo3D:public IAmmo
{
public:
	Ammo3D() {};
	Sphere sphere;
	
	void Shot3D(int m_x, int m_y,int m_z);
	
	
	Ammo3D(const VECTOR& pos);

	void Draw();
	void Update(const float AMMOVELOCITY);
	void Move3D(const float AMMOVELOCITY);
	void Attack3D(const VECTOR& shotpos);

	void Trigger(const VECTOR& shotpos);
	
	int ammomodel;
	bool IsDirty_AmmoTrigger = false;
	bool GetIsDirty() const{ return IsDirty_AmmoTrigger; }
	void SetIsDirty(bool in_isdirty) { IsDirty_AmmoTrigger = in_isdirty; }
	//ダーティフラグ
};

