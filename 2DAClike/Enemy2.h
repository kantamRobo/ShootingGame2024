#pragma once
#include "RootObject2D.h"
class Enemy2:public RootObject2D
{
public:
	Enemy2(const VECTOR& vector) {position = vector; };
	void Update()override;
	void Update(char* input)override;
};


