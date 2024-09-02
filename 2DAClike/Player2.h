#pragma once
#include "RootObject2D.h"
class Player2:public RootObject2D
{
public:
	Player2(const VECTOR& vector) { position = vector; };
	virtual void  Update(char* input)override;
	
	void Update()override;
};

