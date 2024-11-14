#pragma once
#include "RootObject3D.h"
class Ground :public RootObject3D
{
public:
	VERTEX3D vertex[4];
	Ground(float scale)
	{
		//�����`�̍쐬
		vertex[0].pos = VGet(-scale, 0, -scale);
		vertex[1].pos = VGet(-scale, 0, scale);
		vertex[2].pos = VGet(scale, 0, -scale);
		vertex[3].pos = VGet(scale, 0, scale);
	}
	void Draw() override
	{
		DrawPolygon3D(vertex, 2, GetColor(255, 255, 255), TRUE);
	}

	VECTOR position;

	void Set()
	{

		//���_��position�ɏ�Z���āAposition���Ground���ړ�
		for (int i = 0; i < 4; i++)
		{
			vertex[i].pos = VAdd(vertex[i].pos, position);
		}

};

