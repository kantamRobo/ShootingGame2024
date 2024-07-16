#pragma once
#include "RootObject3D.h"

class Player3:public RootObject3D
{
public:
	void Draw()override;
	void Update()override;
	void Update(char* input)override;
	
	
};

