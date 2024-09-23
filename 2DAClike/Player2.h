#pragma once
#include "RootObject2D.h"
class Player2:public RootObject2D
{
public:
	Player2(const VECTOR& vector) {
		position = vector;
		distance = 10;
		boostlimit = EditableBoostLimitParam;
		// �R���X�g���N�^�ŏ�����
		moveDuration = 0.2f;  // 0.2�b�Ԉړ�
		isMoving = false;
	};
	virtual void  Update(char* input)override;
	float inputdelta = 0;
	void Update()override;
	float boostlimit = 0;
	const float EditableBoostLimitParam = 0.4f;
	// �{�^���̏�Ԃ��L�^����ϐ�
	bool isButtonPressed = false;
	bool isButtonReleased = true; // ������Ԃł̓{�^���͗�����Ă���

private:
	bool isMoving;          // �v���C���[���ړ������ǂ���
	float moveDuration;     // �ړ����鎞�ԁi�b�j
	float moveStartTime;    // �ړ����J�n��������
};

