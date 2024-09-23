
#include "RootObject2D.h"

RootObject2D::RootObject2D(const Circle& in_circle) :circle(in_circle)
{
}

void RootObject2D::Init2D(const TCHAR* filepath)
{

	circle.radius = 10;
	
	//handle = MV1LoadModel(filepath);
	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i] = std::make_shared<Ammo2D>(this->position);
		ammo[i]->Setradius(10);
		ammo[i]->SetIsActive(false);
	}
}

void RootObject2D::Draw2D(const VECTOR& vector)
{
	DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), radius, GetColor(255, 255, 255), TRUE);
	
}

float f(float x)
{
	return 5*x*x;
}

void RootObject2D::LockOnMove2D(VECTOR enemypos,float vertical)
{
	
	DrawFormatString(320, 160, GetColor(0, 255, 0), L"����: %f ", acceleration);
position.x = static_cast<float>(enemypos.x +distance* cos( vertical));

position.y = static_cast<float>(enemypos.y+distance * sin(vertical));

}

void RootObject2D::UpdateCore2D()
{


	circle.position = position;
}

void RootObject2D::ControlBoosting_Cooling()
{
	
	//Cooling��true�̏ꍇ�Acoolingtime��0�ɂȂ�܂Ō�������B
	if (coolingtime > 0)
	{
		coolingtime -= deltaTime;
	}
	else
	{
		coolingtime += deltaTime;
		Cooling = false;
	}


	if (coolingtime < boostlimit)//boostlimit�܂ŒB���Ă��Ȃ��ꍇ�ABoosting��true�ƂȂ�
	{
		Boosting = true;
	}
	else
	{
		Boosting = false;
		if (coolingtime > 0)
		{
			Cooling = true;
		}
	}
}

