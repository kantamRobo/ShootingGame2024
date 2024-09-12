
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
void RootObject2D::QuickBoost2DRight(VECTOR enemypos,float& vertical)
{
	
		
	 acceleration += f(deltaTime);

	 if (acceleration > boost)
	 {

		 acceleration = boost;
		
		
		 vertical += acceleration;
		 acceleration = 0;
		
	 }
	 else
	 {
		 vertical += acceleration;
		 acceleration = 0;
	 }
	 
	


	

	position.x = static_cast<float>(enemypos.x +distance * cos(vertical));
	position.y = static_cast<float>(enemypos.y + distance * sin(vertical));
	deltaTime = 0;
	acceleration = 0;
	
}

void RootObject2D::LockOnMove2D(VECTOR enemypos,float vertical)
{
	
	DrawFormatString(320, 160, GetColor(0, 255, 0), L"‰Á‘¬: %f ", acceleration);
position.x = static_cast<float>(enemypos.x +distance* cos( vertical));

position.y = static_cast<float>(enemypos.y+distance * sin(vertical));

}

void RootObject2D::UpdateCore2D()
{


	circle.position = position;
}

