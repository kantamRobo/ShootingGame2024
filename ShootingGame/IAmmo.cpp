#include "IAmmo.h"
#include "IAmmo.h"



IAmmo::IAmmo(const VECTOR& pos)
{
	//sphere.position = pos;

	//sphere.radius = 40;
	//ammomodel = MV1LoadModel(L"C:\\Users\\hatte\\source\\repos\\ShootingGame2024\\ShootingGame3D\\���f��\\�e.mv1");
}



void IAmmo::Draw()
{
	/*
	if (GetIsActive() == true) {
		MV1DrawModel(ammomodel);
		sphere.DrawDebug(position);
	}
	*/

}
void IAmmo::Update(const float AMMOVELOCITY)
{

	Draw();


	MV1SetPosition(ammomodel, position);
	if (GetIsActive() == true) {
		Move3D(AMMOVELOCITY);
	}

}


//�e���ړ�����
void IAmmo::Move(const float AMMOVELOCITY)
{
	position.z += AMMOVELOCITY;
}
//�܂������ĂȂ��e��T������B
void Ammo::Attack3D(const VECTOR& shotpos)
{

	Trigger(shotpos);



}



void IAmmo::Trigger(const VECTOR& shotpos)
{


	//�_�[�e�B�t���O���g��

		//Attack3D�����x�Ăяo����Ă��܂��A���ʈʒu���v���C���[�̈ʒu�ɍX�V����Ă���B
		//����񂾂��Ă�
	Shot3D(shotpos.x, shotpos.y, shotpos.z);

	SetIsActive(true);
	SetIsDirty(true);


}


//�e�𔭎˂���B���m�Ɍ����ƁA�e�̈ʒu�������̈ʒu�ɍX�V����B
void IAmmo::Shot3D(int m_x, int m_y, int m_z)
{


	SetPosition(VGet(m_x, m_y, m_z));






}


