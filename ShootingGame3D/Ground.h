#pragma once
#include "BlankObject.h"
class Ground :public RootObject3D
{
public:
	VERTEX3D vertex[4];
	Ground(float scale,std::shared_ptr<RootObject3D> in_parent)
	{
		this->parent = in_parent;
		//�O�p�`���쐬���āA�l�p�`���쐬
		vertex[0].pos = VGet(-scale, 0, -scale);
		vertex[1].pos = VGet(-scale, 0, scale);
		vertex[2].pos = VGet(scale, 0, -scale);
		vertex[3].pos = VGet(scale, 0, scale);
	}
	void Draw() override
	{
		DrawTriangle3D(vertex[0].pos, vertex[1].pos, vertex[2].pos, DX_NONE_GRAPH, true);
		DrawTriangle3D(vertex[1].pos, vertex[2].pos, vertex[3].pos, DX_NONE_GRAPH, true);
	}

	
	void Set()
	{

		//���_��position�ɏ�Z���āAposition���Ground���ړ�
		for (int i = 0; i < 4; i++)
		{
			vertex[i].pos = (vertex[i].pos, localPosition);
		}
	}

};

