#pragma once

class RootObject3D;

class Enemy3D:public RootObject3D
{
public:
	Enemy3D(const VECTOR& in_pos)  {
		position = in_pos;
		sphere.position = position;
		sphere.radius = OBJECT_SPHERE_RADIUS;

		ammoindex = 0;
	}
	
	void Draw()override;

	void Update(const MATRIX& RotY,Camera* camera=nullptr, char* input=nullptr)override;
	


	
	
	
};

