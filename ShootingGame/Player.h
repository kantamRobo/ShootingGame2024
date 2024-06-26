#pragma once
#include <DxLib.h>
#include "RootObject.h"
#include <memory>

class Player:public RootObject
{public:
	

	
	bool isActive = true;
	int radius = 10;
	int rapid = 0;
	int Color = GetColor(255, 255, 255);
	int ammoindex = 0;
	void Update()override;
	void Draw()override;
	void  Create(double, double);
	void Update(char* input)override;
	
};

