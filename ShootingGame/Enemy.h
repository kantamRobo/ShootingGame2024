#pragma once
#include <DxLib.h>


#include "IRootObject.h"
class Player;
class Enemy:public IRootObject
{
public:
	
	int Color = GetColor(255, 0,0);
	
	void Draw()override;
	 void  Create(double, double);
	
	
	
	void Update(ICamera* camera=nullptr,char* input =nullptr)override
	{}
	
	
	int ammoindex = 0;
};

