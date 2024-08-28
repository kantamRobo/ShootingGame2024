#pragma once
#include <memory>
#include "DEFINE.h"
#include "DEFINE3D.h"
#include "IRootObject.h"
#include "SphereCollision.h"
#include "Ammo3D.h"
//class Ammo3D;
class RootObject3D:public IRootObject
{
public:
	RootObject3D() {};
	int handle=0;
	
	
	Sphere sphere;
	RootObject3D(const Sphere& in_sphere);
	void Init3D(const TCHAR* filepath);
	std::shared_ptr<Ammo3D> ammo[256];
	virtual void Draw3D(const VECTOR& vector);

	void Update_Core3D();

	void AttackTrigger();

	void Attack3D(int index);

	

	

	virtual void Update(char* input) = 0;
	virtual void Update()=0;
	int bulletcounter = 0;
	int ammoindex = 0;


	
};

