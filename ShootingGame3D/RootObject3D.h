#pragma once

#include "SphereCollision.h" // Sphere構造体の定義をインクルード
#include "DEFINE.h"
#include "RootObject.h"

class RootObject3D:public RootObject
{
public:
	int handle=0;
	
	
	
	Sphere sphere;
	virtual void Init3D(const TCHAR* filepath, const VECTOR& position);

	virtual void Draw3D(const VECTOR& vector);

	
	virtual void Update(const VECTOR& vec);
	virtual void Attack3D();
};

