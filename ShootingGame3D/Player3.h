#pragma once
#include "RootObject3D.h"

class Player3:public RootObject3D
{
public:
	Player3();
	void Draw()override;
	void Update()override;

	void Update(char* input)override;

};

