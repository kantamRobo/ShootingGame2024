#pragma once
#include "RootObject2D.h"
class Player2:public RootObject2D
{
public:
	Player2(const VECTOR& vector) {
		position = vector;
		distance = 10;
		boostlimit = EditableBoostLimitParam;
	};
	virtual void  Update(char* input)override;
	
	void Update()override;
	float boostlimit = 0;
	const float EditableBoostLimitParam = 10;
	// �{�^���̏�Ԃ��L�^����ϐ�
	bool isButtonPressed = false;
	bool isButtonReleased = true; // ������Ԃł̓{�^���͗�����Ă���
};

