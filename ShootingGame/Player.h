#pragma once
#include <DxLib.h>
#include "Ammo.h"
#include <memory>
class Player
{public:
	

	VECTOR position = VGet(0, 0, 0);
	std::shared_ptr<Ammo> ammo[50];
	int radius = 10;
	int rapid = 0;
	int Color = GetColor(255, 255, 255);
	int ammoindex = 0;
	void Draw();
	void Create(double xpos, double ypos);
	void Update(char* input);
	
};

