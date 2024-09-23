#include "Player2.h"

void Player2::Update(char* input)
{
	DrawFormatString(320, 200, GetColor(0, 255, 0), L"�p�x %f ", lockontheta);
	DrawFormatString(320, 180, GetColor(0, 255, 0), L"�f���^�^�C��: %f ", deltaTime);
	DrawFormatString(320, 120, GetColor(0, 255, 0), L"�u�[�X�g���~�b�g: % f ", boostlimit);
	DrawFormatString(320, 220, GetColor(0, 255, 0), L"�N�[�����O�Q�[�W: % f ", coolingtime);
	coolingtime /= 10000;
	//Z����u���������ƁA�e���|�[�g����B
	currentTime = static_cast<float>(GetNowCount());
	deltaTime = (currentTime - moveStartTime) / 1000.0f;



	LockOnMove2D(VGet(100, 200, 0), lockontheta);

	// Z�L�[���������Ƃ���0.2�b�Ԉړ�
	if (input[KEY_INPUT_Z] == 1 && !isMoving)
	{
		isMoving = true;
		moveStartTime = GetNowCount(); // �ړ����J�n�������Ԃ��L�^
	}

	// �ړ����L���ȏꍇ
	if (isMoving)
	{
		// ���݂̎��Ԃƈړ��J�n���Ԃ��r���āA�ړ����Ԃ�0.2�b�����Ȃ�ړ�
		float currentTime = GetNowCount();
		if (deltaTime< moveDuration)
		{
			// �����ňړ����������s���܂�
			lockontheta += 0.2f*deltaTime;  // ��: 5�s�N�Z���E�Ɉړ�
		}
		else
		{
			// �ړ����Ԃ��߂������~
			isMoving = false;
		}
	}
	if (input[KEY_INPUT_UP] == 1)
	{
		distance += 0.5;
		DrawFormatString(320, 240, GetColor(0, 255, 0), L" %f ", distance);
	}

	if (input[KEY_INPUT_DOWN] == 1)
	{
		distance -= 0.5;
		DrawFormatString(320, 240, GetColor(0, 255, 0), L" %f ", distance);
	}

	if (input[KEY_INPUT_LEFT] == 1) {


		lockontheta -= 0.1f;

	}

	if (input[KEY_INPUT_RIGHT] == 1)
	{

		lockontheta += 0.1f;


	}
	if (input[KEY_INPUT_A] == 1)
	{

		AttackTrigger();
	}




}


void Player2::Update()
{
	
	Draw2D(this->position);
}
//��