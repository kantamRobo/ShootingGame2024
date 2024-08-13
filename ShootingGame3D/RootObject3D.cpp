

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



