#pragma once
#include "RootObject.h"
class RootObject3D
{
public:
	int handle=0;
	
	
	virtual void Init3D(const TCHAR* filepath);

	virtual void Draw3D(const VECTOR& vector);

	
	virtual void Update(const VECTOR& vec);
	
};

