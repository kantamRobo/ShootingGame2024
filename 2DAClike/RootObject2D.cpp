#include "RootObject2D.h"

RootObject2D::RootObject2D(const Circle& in_sphere) :sphere(in_sphere)
{
}

void RootObject2D::Init2D(const TCHAR* filepath)
{



	handle = MV1LoadModel(filepath);
	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i] = std::make_shared<Ammo3D>(this->position);

		ammo[i]->SetIsActive(false);
	}
}

void RootObject2D::Draw2D(const VECTOR& vector)
{
	DrawCircle(position.x, position.y, radius, GetColor(255, 255, 255), TRUE);
	
}

void RootObject2D::UpdateCore2D()
{


	circle.position = position;
}

