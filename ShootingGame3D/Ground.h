#pragma once
#include "RootObject3D.h"
class Ground :public RootObject3D
{
public:
	VERTEX3D vertex[4];
	Ground(float scale)
	{
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
			vertex[i].pos = VAdd(vertex[i].pos, position);
		}

};

