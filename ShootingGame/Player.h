#pragma once
#include <DxLib.h>
#include "RootObject.h"
#include <memory>

class Player:public RootObject
{public:
	

	
	bool isActive = true;
	
	
	int Color = GetColor(255, 255, 255);
	
	void Update()override;
	void Draw()override;
	void  Create(double, double);
	void Update(char* input)override;
	
};

