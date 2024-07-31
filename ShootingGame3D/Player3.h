#pragma once
#include "RootObject3D.h"
#include "SphereCollision.h"
class Player3:public RootObject3D
{
public:
	playersphere();
	void Draw()override;
	void Update()override;
	void Update(char* input)override;
	
	Sphere playersphere;
};

