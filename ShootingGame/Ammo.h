#pragma once
#include <DxLib.h>
class Ammo
{
public:
	Ammo() : AMMOVELOCITY(10.0f)
	{};
	
	VECTOR position = VGet(0, 0, 0);
	bool isActive = false;
	const int AMMOVELOCITY = 10;//�n�[�h�R�[�h����Ă��܂��Ă���B
	

	
	bool GetIsActive()const { return isActive; }
	void Shot(int m_x, int m_y);
	int radius = 10;
	void Update();

	void EnemyUpdate();

	virtual void Move3D(const float AMMOVELOCITY) = 0;
	
};

