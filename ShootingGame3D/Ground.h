#pragma once
#include "BlankObject.h"
class Ground :public RootObject3D
{
public:
	VERTEX3D vertex[4];
	Ground(float scale,std::shared_ptr<RootObject3D> in_parent)
	{
		this->parent = in_parent;
		//三角形を二つ作成して、四角形を作成
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

		//頂点をpositionに乗算して、position基準にGroundを移動
		for (int i = 0; i < 4; i++)
		{
			vertex[i].pos = (vertex[i].pos, localPosition);
		}
	}

};

