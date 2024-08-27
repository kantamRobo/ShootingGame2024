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
	const int ENEMY_X_LIMIT = 200;
	const int ENEMY_Z_LMIIT = 50;
	void Update(char* input)override;
	
};

