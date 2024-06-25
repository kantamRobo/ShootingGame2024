#pragma once
#include <DxLib.h>
#include "Ammo.h"
#include "Player.h"
#include "RootObject.h"
class Enemy:public RootObject 
{
public:
	VECTOR position = VGet(0, 0, 0);
	int Color = GetColor(255, 0,0);
	int radius=10;
	void Draw()override;
	void Create(double xpos, double ypos)override;
	void Move();
	void Attack(const Player& player);
	
	std::shared_ptr<Ammo> ammo[10]; //Ammoが抽象クラスになってしまうので、ポインタにする。
	Player player;
	int ammoindex = 0;
};

