#pragma once
#include <DxLib.h>
#include <memory>
#include "IRootObject.h"

class RootObject2D:public IRootObject
{


public:
	RootObject2D() {};
	int handle = 0;
	float lockonOmega = 0;
	float lockonradius = 0;
	
	RootObject2D(const Circle& in_sphere);
	void Init2D(const TCHAR* filepath);
	
	virtual void Draw2D(const VECTOR& vector);
	
	
	
	virtual  void LockOnMove2D(VECTOR enemypos, float vertical, double horizontal);
	void UpdateCore2D();



	Circle circle;

	virtual void Update(char* input) = 0;
	virtual void Update() = 0;
	int bulletcounter = 0;
	int ammoindex = 0;
	float GetLockonOmega() { return lockonOmega; }
	float Getlockonradius() { return lockonradius; }
	void SetLockonRadius(float radius) { lockonradius = radius; }
	void SetLockonOmega(float omega) { lockonOmega = omega; }
};



