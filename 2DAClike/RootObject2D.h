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


	//敵とプレイヤーの角度を計算する。
	static double Angle2D(const VECTOR& from, const VECTOR& to)
	{

		double dot = VDot(from, to);


		auto Amag = VSquareSize(from);

		auto Bmag = VSquareSize(to);
		double cos = dot / (Amag * Bmag);

		double radian = acos(cos);
		double degree = radian * RAD_TO_DEG;

		return degree;

	}




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



