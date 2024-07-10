#include "RootObject3D.h"

void RootObject3D::Init3D( const TCHAR* filepath)
{

	 
	handle = MV1LoadModel(filepath);
}

void RootObject3D::Draw3D(const VECTOR& vector)
{

	MV1SetPosition(handle, vector);

	MV1DrawModel(handle);
}

void RootObject3D::Update(const VECTOR& vec)
{
	Draw3D(vec);
}


