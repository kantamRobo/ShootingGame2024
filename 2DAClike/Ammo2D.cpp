#include "Ammo2D.h"




Ammo2D::Ammo2D(const VECTOR& pos)
{
	circle.position = pos;

	circle.radius = 40;
	//ammomodel = MV1LoadModel(L"C:\\Users\\hatte\\source\\repos\\ShootingGame2024\\ShootingGame3D\\���f��\\�e.mv1");
}



void Ammo2D::Draw()
{
	DrawCircle(position.x, position.y, static_cast<int>(radius), GetColor(255,255,255), TRUE);

}
void Ammo2D::Update(const float AMMOVELOCITY)
{

	Draw();


	
	if (GetIsActive() == true) {
		Move2D(AMMOVELOCITY);
	}

}


//�e���ړ�����
void Ammo2D::Move2D(const float AMMOVELOCITY)
{
	position.y += AMMOVELOCITY;
}
//�܂������ĂȂ��e��T������B
void Ammo2D::Attack2D(const VECTOR& shotpos)
{

	Trigger(shotpos);



}



void Ammo2D::Trigger(const VECTOR& shotpos)
{


	//�_�[�e�B�t���O���g��

		//Attack3D�����x�Ăяo����Ă��܂��A���ʈʒu���v���C���[�̈ʒu�ɍX�V����Ă���B
		//����񂾂��Ă�
	Shot2D(shotpos.x, shotpos.y);

	SetIsActive(true);
	


}


//�e�𔭎˂���B���m�Ɍ����ƁA�e�̈ʒu�������̈ʒu�ɍX�V����B
void Ammo2D::Shot2D(int m_x, int m_y)
{


	SetPosition(VGet(m_x, m_y,0));






}


