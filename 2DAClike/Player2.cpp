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
	deltaTime = static_cast<float>(currentTime - previousTime) / 4000; // �~���b����b�ɕϊ�
	



	LockOnMove2D(VGet(100, 200, 0), lockontheta);

	if (input[KEY_INPUT_Z] == 1)
	{
		

		previousTime = static_cast<float>(GetNowCount());
		
		
		ControlBoosting_Cooling();


		//Boosting��false�ŁAcoolingtime��0�łȂ���΁ABoosting��false�̂܂�

		if (Boosting && !Cooling)
		{
			

			lockontheta += 0.3f;
		}
		else
		{
			
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