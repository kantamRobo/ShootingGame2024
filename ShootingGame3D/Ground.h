#pragma once
#include "BlankObject.h"
class Ground :public RootObject3D
{
public:
	VERTEX3D vertex[4];
	Ground(float scale,std::shared_ptr<RootObject3D> in_parent)
	{
		this->parent = in_parent;
		//³•ûŒ`‚Ìì¬
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

		//’¸“_‚ğposition‚ÉæZ‚µ‚ÄApositionŠî€‚ÉGround‚ğˆÚ“®
		for (int i = 0; i < 4; i++)
		{
			vertex[i].pos = (vertex[i].pos, position);
		}
	}

};

