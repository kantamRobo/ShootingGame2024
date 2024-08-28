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
	virtual void Update()override;
	
	void Update(char* input)override;
	
};

