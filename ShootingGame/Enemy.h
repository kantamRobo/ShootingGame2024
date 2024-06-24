#pragma once
#include <DxLib.h>
#include "Ammo.h"
#include "Player.h"
class Enemy
{
public:
	VECTOR position = VGet(0, 0, 0);
	int Color = GetColor(255, 0,0);
	int radius=10;
	void Draw();
	void Create(double xpos, double ypos);
	void Move();
	void Attack(const Player& player);
	
	Ammo ammo[10];
	Player player;
	int ammoindex = 0;
};

