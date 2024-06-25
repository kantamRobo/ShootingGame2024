#pragma once
#include <DxLib.h>


#include "RootObject.h"
class Player;
class Enemy:public RootObject 
{
public:
	VECTOR position = VGet(0, 0, 0);
	int Color = GetColor(255, 0,0);
	int radius=10;
	void Draw()override;
	void Create(double xpos, double ypos)override;
	void Move();
	void Update()override;
	void Attack(const std::shared_ptr<Player> player);
	void Update(char*)override
	{}
	
	
	int ammoindex = 0;
};

