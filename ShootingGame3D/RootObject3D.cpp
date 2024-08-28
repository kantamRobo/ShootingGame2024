

#include "RootObject3D.h"


RootObject3D::RootObject3D(const Sphere& in_sphere):sphere(in_sphere)
{
}



void RootObject3D::Init3D( const TCHAR* filepath)
{
	
	
	
	handle = MV1LoadModel(filepath);
	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i] = std::make_shared<Ammo3D>(this->position);
		
		ammo[i]->SetIsActive(false);
	}
}

void RootObject3D::Draw3D(const VECTOR& vector)
{

	MV1SetPosition(handle, position);
	
	MV1DrawModel(handle);
}



void RootObject3D::Update_Core3D()
{

	sphere.position = position;
	sphere.DrawDebug(position);

}


void RootObject3D::AttackTrigger()
{
	bulletcounter += 1;
	bulletcounter %= 5000;
	if (bulletcounter % 100 == 0) {
		ammoindex++;
		Attack3D(ammoindex);
	}
	else if (ammoindex == MAX_AMMO - 1)
	{
		ammoindex = 0;
	}
}

void RootObject3D::Attack3D(int index)
{



	ammo[index]->Attack3D(this->position);






}