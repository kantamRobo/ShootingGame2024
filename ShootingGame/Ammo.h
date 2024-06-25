#pragma once
#include <DxLib.h>
#include "RootObject.h"
class Ammo:public RootObject
{
public:
	VECTOR position = VGet(0, 0, 0);
	bool isActive = true;
	const int AMMOVELOCITY = 10;
	

	Ammo();
	bool GetIsActive()const { return isActive; }
	void Shot(int m_x, int m_y);

	void Update();

	void EnemyUpdate();

	

};

