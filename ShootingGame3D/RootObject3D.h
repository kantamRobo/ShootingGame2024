#pragma once
#include <memory>
#include "DEFINE.h"
#include "RootObject.h"
#include "SphereCollision.h"
#include "Ammo3D.h"
class RootObject3D:public RootObject
{
public:
	int handle=0;
	
	
	
	Sphere sphere;
	virtual void Init3D(const TCHAR* filepath, const VECTOR& position);
	std::shared_ptr<Ammo3D> ammo[10];
	virtual void Draw3D(const VECTOR& vector);

	virtual void Update(char* input) = 0;
	virtual void Update()=0;
	virtual void Attack3D();
};

