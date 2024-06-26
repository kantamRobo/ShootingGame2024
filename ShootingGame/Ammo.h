#pragma once
#include <DxLib.h>
class Ammo
{
public:
	VECTOR position = VGet(0, 0, 0);
	bool isActive = false;
	const int AMMOVELOCITY = 10;
	

	Ammo();
	bool GetIsActive()const { return isActive; }
	void Shot(int m_x, int m_y);
	int radius = 10;
	void Update();

	void EnemyUpdate();

	

};

