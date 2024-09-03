#include "Ammo2D.h"
#include <math.h>




Ammo2D::Ammo2D(const VECTOR& pos)
{
	circle.position = pos;

	circle.radius = 40;
	//ammomodel = MV1LoadModel(L"C:\\Users\\hatte\\source\\repos\\ShootingGame2024\\ShootingGame3D\\���f��\\�e.mv1");
}



void Ammo2D::Draw()
{
	if (isActive) {
		DrawCircle(position.x, position.y, static_cast<int>(radius), GetColor(0, 255, 0), TRUE);
	}
}
void Ammo2D::Update(const float AMMOVELOCITY,const VECTOR& objectpos,float objectangle)
{

	Draw();


	
	if (GetIsActive() == true) {
		Move2D(AMMOVELOCITY,objectpos,objectangle);
	}

}


//�e���ړ�����
void Ammo2D::Move2D(const float AMMOVELOCITY,const VECTOR& objectpos,float objectangle)
{
	
	
	
	
	
	position.x = (position.x + cos(m_angle) * -AMMOVELOCITY);
	position.y = (position.y + sin(m_angle) * -AMMOVELOCITY);
	
	
}
//�܂������ĂȂ��e��T������B
void Ammo2D::Attack2D(const VECTOR& shotpos,float objectangle)
{

	Trigger(shotpos,objectangle);



}



void Ammo2D::Trigger(const VECTOR& shotpos,float objectangle)
{


	//�_�[�e�B�t���O���g��

		//Attack3D�����x�Ăяo����Ă��܂��A���ʈʒu���v���C���[�̈ʒu�ɍX�V����Ă���B
		//����񂾂��Ă�
	Shot2D(shotpos.x, shotpos.y,objectangle);
	SetIsActive(true);
	


}


//�e�𔭎˂���B���m�Ɍ����ƁA�e�̈ʒu�������̈ʒu�ɍX�V����B
void Ammo2D::Shot2D(int m_x, int m_y,float angle)
{
	SetPosition(VGet(m_x, m_y,0));



	m_angle = angle;


}


