#pragma once
#include "RootObject3D.h"



class Player3:public RootObject3D
{
public:
	Player3();
	void Draw()override;
	void Update()override;
	float inputdelta = 0;
	void Update(char* input)override;
	void PlayerInput(char* input);

	
	
	
	int bulletcounter = 0;
	int ammoindex = 0;

	
};

