#pragma once



#include <DxLib.h>
#include "IAmmo.h"
class Ammo2D:public IAmmo
{
public:
	Ammo2D() {};
	


	Ammo2D(const VECTOR& pos);

	void Draw();
	void Update(const float AMMOVELOCITY, const VECTOR& objectpos, float objectangle)override;
	
	
	VECTOR ammodistance;
	
	void Move2D(const float AMMOVELOCITY, const VECTOR& objectpos, float objectangle);
	void Attack2D(const VECTOR& shotpos, float objectangle);
	

	void Trigger(const VECTOR& shotpos, float objectangle);

	

	void Shot2D(int m_x, int m_y, float angle);

	

	float m_angle=0;

	float radius;
	void Setradius(float in_radius) { radius = in_radius; }
	float Getradius() { return radius; }
	Circle circle;

	

};

