#include "SphereCollision.h"
#include "DEFINE.h"
#include "DEFINE3D.h"
#include "Ammo3D.h"

Ammo3D::Ammo3D(const VECTOR& pos)
{
	sphere.position = pos;

	sphere.radius = AMMO_SPHERE_RADIUS;
	ammomodel= MV1LoadModel(L"C:\\Users\\hatte\\source\\repos\\ShootingGame2024\\ShootingGame3D\\���f��\\�e.mv1");

}



void Ammo3D::Draw()
{
	if (GetIsActive() == true) {
		MV1DrawModel(ammomodel);
		sphere.DrawDebug(position);
	}
	
	
}
void Ammo3D::Update(const float AMMOVELOCITY)
{

	Draw();
	
	sphere.position = position;
	MV1SetPosition(ammomodel, position);
	if (GetIsActive() == true) {
		Move3D(AMMOVELOCITY);
	
	}
	
}


//�e���ړ�����
void Ammo3D::Move3D(const float AMMOVELOCITY)
{
	position.z += AMMOVELOCITY;
}
//�܂������ĂȂ��e��T������B
void Ammo3D::Attack3D(const VECTOR& shotpos)
{
	
		Trigger(shotpos);
	
	

}



void Ammo3D::Trigger(const VECTOR& shotpos)
{

	
			Shot3D(shotpos.x, shotpos.y, shotpos.z);
		
			SetIsActive(true);
			
	
	
}


//�e�𔭎˂���B���m�Ɍ����ƁA�e�̈ʒu�������̈ʒu�ɍX�V����B
void Ammo3D::Shot3D(float m_x, float m_y, float m_z)
{
	

		SetPosition(VGet(m_x, m_y, m_z));
			


	

	
}


