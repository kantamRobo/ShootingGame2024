#pragma once
#include <DxLib.h>
#include "DEFINE.h"
#include "DEFINE2D.h"
class Ammo2D
{
public:
	Ammo2D() {};
	
	VECTOR position = VGet(0, 0, 0);
	bool isActive = false;
	void SetIsActive(bool in_isactive) { isActive = in_isactive; }
	bool GetIsActive()const { return isActive; }
	virtual void PlayerUpdate()=0;

	virtual void EnemyUpdate()=0;
	//ここまでインターフェイスに移動。UpdateとEnemyUpdateは、UpdateはPlayerUpdateに改名したのち、それぞれ純水仮想関数にしてインターフェイスに移動。
	void Shot2D(int m_x, int m_y);
	
	
	int radius2D = 10;
	

	
	void SetRadius2D(int in_radius2D)
	{
		radius2D = in_radius2D;
	}

	int GetRadius2D(){
		return radius2D;
	}
	
};

