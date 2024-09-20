#pragma once
//#include "RootObject3D.h"
#include "Camera.h"
class RootObject3D;

class Player3:public RootObject3D
{
public:
	Player3(const VECTOR& in_pos) {
		position = in_pos;
		sphere.position = position;
		sphere.radius = OBJECT_SPHERE_RADIUS;

		ammoindex = 0;
	}
	Camera camera;
	VECTOR move;
	void Draw()override;
	void Update()override;
	float inputdelta = 0;
	void Update(char* input)override;
	void PlayerInput(char* input);

	void Move(char* input);

	

	
	
	
	int bulletcounter = 0;
	int ammoindex = 0;
    float move_horizontal = 0;
	float move_vertical = 0;
	
};

