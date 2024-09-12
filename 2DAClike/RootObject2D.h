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

	// DeltaTime�̏�����
	float currentTime =0; // ���݂̎��ԁi�~���b�j
	float previousTime = currentTime;  // �O��̃t���[���̎���
	float deltaTime = 0.0f;          // �o�ߎ���
	int quick_boostguage = 0;
	const float boost = 10;
	float acceleration = 0;
	//�G�ƃv���C���[�̊p�x���v�Z����B
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



