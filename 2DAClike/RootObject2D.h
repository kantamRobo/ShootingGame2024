#pragma once
#include <DxLib.h>
#include <memory>
#include "IRootObject.h"

class RootObject2D:public IRootObject
{


public:
	RootObject2D() {};
	int handle = 0;
	float lockonradius = 0;
	
	RootObject2D(const Circle& in_sphere);
	void Init2D(const TCHAR* filepath);
	
	virtual void Draw2D(const VECTOR& vector);

	
	
	
	

	void QuickBoost2DRight(VECTOR enemypos, float& vertical);

	void LockOnMove2D(VECTOR enemypos, float vertical);
	void UpdateCore2D();

	// DeltaTimeの初期化
	float currentTime =0; // 現在の時間（ミリ秒）
	float previousTime = currentTime;  // 前回のフレームの時間
	float deltaTime = 0.0f;          // 経過時間
	int quick_boostguage = 0;
	const float boost = 10;
	float acceleration = 0;
	//敵とプレイヤーの角度を計算する。
	inline static double Angle2D(const VECTOR& from, const VECTOR& to)
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
	
	float Getlockonradius() { return lockonradius; }
	void SetLockonRadius(float radius) { lockonradius = radius; }

};



