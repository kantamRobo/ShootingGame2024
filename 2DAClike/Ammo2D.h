#pragma once



#include <DxLib.h>
#include "IAmmo.h"
class Ammo2D:public IAmmo
{
public:
	Ammo2D() {};
	


	Ammo2D(const VECTOR& pos);

	void Draw();
	void Update(const float AMMOVELOCITY);
	void Move2D(const float AMMOVELOCITY);
	void Attack2D(const VECTOR& shotpos);

	void Trigger(const VECTOR& shotpos);

	void Shot2D(int m_x, int m_y);

	

	float radius;
	void Setradius(float in_radius) { radius = in_radius; }
	float Getradius() { return radius; }
	Circle circle;

	

};

