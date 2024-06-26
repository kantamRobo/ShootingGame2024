#pragma once
#include <DxLib.h>


#include "RootObject.h"
class Player;
class Enemy:public RootObject 
{
public:
	
	int Color = GetColor(255, 0,0);
	
	void Draw()override;
	 void  Create(double, double);
	void Move();
	void Update()override;
	void Attack(const std::shared_ptr<Player> player);
	void Update(char*)override
	{}
	
	
	int ammoindex = 0;
};

