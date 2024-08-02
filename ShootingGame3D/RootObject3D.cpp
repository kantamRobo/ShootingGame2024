

#include "RootObject3D.h"


void RootObject3D::Init3D( const TCHAR* filepath,const VECTOR& in_position)
{
	position = in_position;
	
	
	handle = MV1LoadModel(filepath);
	for (int i = 0; i < 10; i++)
	{
		ammo[i] = std::make_shared<Ammo3D>();
	}
}

void RootObject3D::Draw3D(const VECTOR& vector)
{

	MV1SetPosition(handle, position);

	MV1DrawModel(handle);
}

void RootObject3D::Update(const VECTOR& vec)
{
	Draw3D(vec);
	
	sphere.DrawDebug(position);
	for (int i = 0; i < 10; i++)
	{
		ammo[i] -> Update3D();
	}
}

void RootObject3D::Attack3D()
{
	rapid++;

	rapid %= RAPID_RATE;

	if (rapid == 1) {

		if (ammo[ammoindex]->isActive == false) {
			ammo[ammoindex]->Shot3D(this->position.x, this->position.y,this->position.z);
			ammo[ammoindex]->isActive = true;
			DrawFormatString(50, 70, GetColor(0, 255, 0), L"�e:%d", ammoindex);

			ammoindex++;
			if (ammoindex == MAX_AMMO - 1) {
				for (int j = 0; j < MAX_AMMO; j++)
				{
					if (ammo[j]->isActive == true) {
						ammo[j]->isActive = false;
					}
					ammoindex = 0;
				}

				//���̑S�T���ł͌v�Z�ʂ��G���j�b�g�Ɣ��Ƃǂ��Ȃ�̂��E�E�E�E�ő��n^10?
				//���񎞍l���邪�A�O�̂��ߓ񕪒T����������悤���K���Ă����B
			}
		}
	}
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
		ammo[i] = std::make_shared<Ammo3D>();
		ammo[i]->isActive = false;
	}
}
