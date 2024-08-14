#pragma once



#include <DxLib.h>
#include "IAmmo.h"
class Ammo2D:public IAmmo
{
public:
	Ammo2D() {};
	void Shot2D(int m_x, int m_y);


	Ammo2D(const VECTOR& pos);

	void Draw();
	void Update(const float AMMOVELOCITY);
	void Move2D(const float AMMOVELOCITY);
	void Attack2D(const VECTOR& shotpos);

	void Trigger(const VECTOR& shotpos);

	void Shot2D(int m_x, int m_y);

	float radius;
	bool IsDirty_AmmoTrigger = false;
	bool GetIsDirty() const { return IsDirty_AmmoTrigger; }
	void SetIsDirty(bool in_isdirty) { IsDirty_AmmoTrigger = in_isdirty; }
};

