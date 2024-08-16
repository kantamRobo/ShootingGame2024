#pragma once
#include <DxLib.h>
#include <memory>
#include "IRootObject.h"
#include "Ammo2D.h"
class RootObject2D:public IRootObject
{


public:
	RootObject2D() {};
	int handle = 0;


	Circle sphere;
	RootObject2D(const Circle& in_sphere);
	void Init2D(const TCHAR* filepath);
	std::shared_ptr<Ammo2D> ammo[256];
	virtual void Draw2D(const VECTOR& vector);
	virtual void LockOnMove2D();
	void UpdateCore2D();





	virtual void Update(char* input) = 0;
	virtual void Update() = 0;
	int bulletcounter = 0;
	int ammoindex = 0;

	
};



