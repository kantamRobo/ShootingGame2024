

#include "RootObject3D.h"


RootObject3D::RootObject3D(const Sphere& in_sphere):sphere(in_sphere)
{
}



int RootObject3D::Init3D( const TCHAR* filepath,const VECTOR& InitPos,const VECTOR& InitLocalPos)
{
	
	position = InitPos;
	localPosition = InitLocalPos;

	
	handle = MV1LoadModel(filepath);
	for (int i = 0; i < MAX_AMMO; i++)
	{
		ammo[i] = std::make_shared<Ammo3D>(this->position);
		
		ammo[i]->SetIsActive(false);
	}
	return handle;
}

void RootObject3D::Draw3D(const VECTOR& vector)
{
	//�e�����Ȃ���΁A�w�肵���O���[�o�����W�ł��̂܂ܕ`�悷��
	if (parent != nullptr) {
		MV1SetPosition(handle, position);
	}
	else {
		//�e������΁A�e�̍��W����ɂ��ăO���[�o�����W�����߂����̂ŁA
		// �e�̃O���[�o�����W����ɂ��ă��[�J�����W��
		//�O���[�o�����W�ɕϊ�����B
		MV1SetPosition(handle, VAdd(position,localPosition));
	}
	MV1DrawModel(handle);
}



void RootObject3D::Update_Core3D()
{
	if (parent) {
	SetLocalPosition(position);
}
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