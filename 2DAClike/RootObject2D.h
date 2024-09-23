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

	
	
	// Lerp�֐�
	float Lerp(float a, float b, float t) {
		return a + (b - a) * t;
	}
	

	

	void LockOnMove2D(VECTOR enemypos, float vertical);
	void UpdateCore2D();

	void ControlBoosting_Cooling();

	

	// DeltaTime�̏�����
	float currentTime =0; // ���݂̎��ԁi�~���b�j
	float previousTime = currentTime;  // �O��̃t���[���̎���
	float deltaTime = 0.0f;          // �o�ߎ���
	
	//�N�C�b�N�u�[�X�g�p�����[�^
	float boostlimit = 0;//boost�̐�������
	float acceleration = 0.0f;//�����x
	float distance = 20.0f;//�v���C���[�ƓG�̋���
	float radius = 5.0f;//�v���C���[�̔��a
	float coolingtime = 0.0f;//�N�[���_�E������
	bool isButtonPressed = false;
	bool isButtonReleased = true; // ������Ԃł̓{�^���͗�����Ă���
	
//������
	bool Boosting = false;
	//��p��
public:
	bool Cooling = false;
	
	
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



