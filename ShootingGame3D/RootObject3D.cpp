#include "RootObject3D.h"
#include "Ammo.h"
void RootObject3D::Init3D( const TCHAR* filepath,const VECTOR& in_position)
{
	position = in_position;
	position.x += 20;
	MV1SetPosition(handle, position);
	handle = MV1LoadModel(filepath);
}

void RootObject3D::Draw3D(const VECTOR& vector)
{

	MV1SetPosition(handle, position);

	MV1DrawModel(handle);
}

void RootObject3D::Update(const VECTOR& vec)
{
	Draw3D(vec);
}


void RootObject::Create(double in_x, double in_y)
{

	position.x = in_x;
	position.y = in_y;
	//�v���C���[�L�����N�^�[�̏ꏊ�����߂�B
 //xpos,ypos�Ƃ����̂́A�u�֐�(���񂷂�)�̈���(�Ђ�����)�v�ƌ�������̂ŁA
//���̊֐����Ăяo���Ƃ��ɁA�Q�[�����n�܂����Ƃ��ɁA�v���C���[���o�Ă���ꏊ
//�͂ǂ��ɂ��邩�H�Ƃ����̂����߂�̂Ɏg���B
	for (int i = 0; i < 10; i++)
	{
		ammo[i] = std::make_shared<Ammo>();
		ammo[i]->isActive = false;
	}
}
